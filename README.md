# Tarwi
**Tarwi** is a lite, header-only, embeddable and easy-to-use library for unit tests in C and C++.
Note that this project is primarily designed for [RadishOS](https://github.com/wither16x/radish_os) and related projects.

## Features
* Modular tests organization
* Manage successfull, failed and skipped tests
* Macros for better code readability and quick writing

## Embed Tarwi in your project
**Embedding** Tarwi in your own project is very simple. No build steps are required as everything is defined in header files.

**Step 1**: clone the repository
```sh
git clone https://github.com/wither16x/tarwi
```
**Step 2**: copy the content of [`Include/`](Include/) in your project directory. For example:
```sh
cp Include/*.hpp MyProject/Test/Tarwi/
```

## Configuration
Since Tarwi is designed to run in restricted environments like **operating system kernels**, it can be **configured** to adapt to its environment.
The recommended way to do it is to create a header - for example `TarwiGlobals.hpp` and write the configuration in it.

The **output function** must be defined. It is used by the `TARWI_OUTPUT()` macro, which expects a **printf-like** signature.
Here is an example on how to define it:
```cpp
#if defined(TARWI_OUTPUT)
        #undef TARWI_OUTPUT
        #define TARWI_OUTPUT(...) \
                do { \
                        myPrintf(__VA_ARGS__); \
                } while (0)
#endif
```
Always do it **before including** `Tarwi.hpp`.

## Tests organization
It is recommended to keep your **tests** away from your source code and headers. You could for example write them in a `Test/` directory.
Tarwi uses **test packages**, which are directories containing **test modules** and a **package header** named `Package.hpp`.

### Modules
A **test module** is a single header file which contains a class which inherits from the `Tarwi::Module` class. You can define it like this:
```cpp
class MyModule : public Tarwi::Module {};
```
You can also use a macro:
```cpp
TARWI_MODULE(MyModule) {};
```
Do not forget to give a **name** to your module, using `TARWI_SET_NAME()`, which takes a null-terminated string and defines a variable called `name` of type `const char *`.

Each module contains private **units**, which are used to execute the tests. A unit is actually a method of type `Tarwi::Result`. It should return using the `TARWI_EXPECT()` macro, which determines if the test failed or not depending on the result of a given expression.
```cpp
// C++ style
class MyModule : public Tarwi::Module {
        Tarwi::Result unitTestSomething()
        {
                // ...
                TARWI_EXPECT(expression);
        }
};

// Tarwi style
TARWI_MODULE(MyModule) {
        TARWI_UNIT(unitTestSomething)
        {
                // ...
                TARWI_EXPECT(expression);
        }
};
```
Every module also has a single public **main method**, which must execute the test units. This method must override the virtual main method of the `Tarwi::Module` class.
```cpp
        // module code
public:
        void main() override
        {
                // call units
        }
};
```
You can also use the `TARWI_MODULE_MAIN()` macro:
```cpp
        // module code
        TARWI_MODULE_MAIN()
        {
                // call units
        }
};
```
To call a unit, use `TARWI_CALL_UNIT()`, which takes the unit name and displays a message depending on the returned value.

### Packages
As explained above, a **test package** is basically a single directory which contains test modules and a single header file named conventionally `Package.hpp`.
This header must define a class which inherits from the `Tarwi::Package` class the following way:
```cpp
class MyPackage : public Tarwi::Package {};
```
Or, with a macro:
```cpp
TARWI_PACKAGE(MyPackage) {};
```
You can give a name to your package the same way that you would do for a module.

Next, declare a private instance of every module in the package.
Finally, define a public main method the same way that you would do for a module. If you want to use a macro, you can do like the following:
```cpp
        // package code
        TARWI_PACKAGE_MAIN()
        {
                // call modules
        }
};
```
Inside the main method, call the modules using `TARWI_CALL_MODULE()`.
Finally, if you want a summary of the tests, you can use `TARWI_DISPLAY_RESULTS(success, failed, skipped)`.

## Miscellaneous
### `Tarwi::Result`
This is an **enum** containing three constants:
* `Failed`
* `Success`
* `Skipped`

### Skip test units easily
To do so, you can use `TARWI_SKIP()` which returns `Tarwi::Result::Skipped`.

## Test project
You can try to build [`TestProject/`](TestProject/) to see how Tarwi testing looks like.
Run the following commands:
```sh
make -C TestProject
./TestProject/Build/Main
```
And you should see something like this:
```
Running package test_package...
Running module MathPackage.integers_module...
Skipped IntegersModule.unitAddition()
IntegersModule.unitSubstraction() successfull
IntegersModule.unitMultiplication() successfull
IntegersModule.unitDivision() successfull
Executed all tests from package MathPackage:
Results: 3 successfull, 0 failed and 1 skipped tests

Hello! My name is Robin and I am a robot!
Running package robot_package...
Running module RobotPackage.setup_module...
SetupModule.unitCheckName() failed
Running module RobotPackage.movement_module...
MovementModule.unitCheckHorizontalMovements() successfull
MovementModule.unitCheckVerticalMovements() successfull
Executed all tests from package RobotPackage:
Results: 2 successfull, 1 failed and 0 skipped tests
```