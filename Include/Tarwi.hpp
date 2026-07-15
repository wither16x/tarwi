#pragma once

// --------------------------------- Macros ---------------------------------

/// Tells Tarwi which function to use to output a formatted string.
/// Tarwi expects a printf-like format.
#define TARWI_OUTPUT(...) \
        do { \
                __tarwiUndefinedOutputFunction(__VA_ARGS__); \
        } while (0)

/// Must be used inside a function / method.
/// This macro determines if the test was successfull or not.
#define TARWI_EXPECT(expr) \
        do { \
                if ((expr)) \
                        return Tarwi::Result::Success; \
                return Tarwi::Result::Failed; \
        } while (0)

/// Call a test unit and display a message depending on the result.
#define TARWI_CALL_UNIT(fname, ...) \
        do { \
                Tarwi::Result result = fname(__VA_ARGS__); \
                if (result == Tarwi::Result::Success) { \
                        TARWI_OUTPUT("%s."#fname"() successfull\n", this->name); \
                        ++this->successfull_tests; \
                } else if (result == Tarwi::Result::Skipped) { \
                        TARWI_OUTPUT("Skipped %s."#fname"()\n", this->name); \
                        ++this->skipped_tests; \
                } else { \
                        TARWI_OUTPUT("%s."#fname"() failed\n", this->name); \
                        ++this->failed_tests; \
                } \
        } while (0)

/// Shortcut to skip a test.
#define TARWI_SKIP() \
        do { \
                return Tarwi::Result::Skipped; \
        } while (0)

/// Run the main method of a test module.
#define TARWI_RUN_MODULE(mname) \
        do { \
                TARWI_OUTPUT("Running module %s."#mname"...\n", this->name); \
                mname.main(); \
        } while (0)

/// Run the main method of a package.
#define TARWI_RUN_PACKAGE(pname) \
        do { \
                TARWI_OUTPUT("Running package "#pname"...\n"); \
                pname.main(); \
        } while (0)

/// Set the name of a module or a package.
#define TARWI_SET_NAME(xname) \
        const char *name = xname;

/// Begin the definition of a test unit.
#define TARWI_UNIT(uname) \
        Tarwi::Result uname()

/// Begin the definition of a test module.
#define TARWI_MODULE(mname) \
        class mname : public Tarwi::Module

/// Begin the definition of a test package
#define TARWI_PACKAGE(pname) \
        class pname : public Tarwi::Package

/// Begin the definition of the main method of a test module.
#define TARWI_MODULE_MAIN() \
        public: void main() override

/// Begin the definition of the main method of a test package.
#define TARWI_PACKAGE_MAIN() \
        public: void main() override

/// Display the amount of successfull, failed and skipped tests.
/// This macro should be used from a package method.
#define TARWI_DISPLAY_RESULTS(successfull, failed, skipped) \
                do { \
                        TARWI_OUTPUT("Executed all tests from package %s:\n", name); \
                        TARWI_OUTPUT("Results: %d successfull, %d failed and %d skipped tests\n", successfull, failed, skipped); \
                } while (0)

namespace Tarwi {

// --------------------------------- Package ---------------------------------
class Package {
public:
        virtual void main()
        {}
};

// --------------------------------- Module ---------------------------------
class Module {
public:
        int successfull_tests = 0;
        int failed_tests = 0;
        int skipped_tests = 0;

        virtual void main()
        {}
};

// --------------------------------- Result ---------------------------------
enum class Result : int {
        Failed,
        Success,
        Skipped
};

} // namespace Tarwi