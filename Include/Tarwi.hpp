#pragma once

// --------------------------------- Macros ---------------------------------

#define TARWI_FMT_STRING                        "%s"
#define TARWI_FMT_INTEGER                       "%d"

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
                        TARWI_OUTPUT(TARWI_FMT_STRING "."#fname"() successfull", this->name); \
                        ++this->successfull_tests; \
                } else if (result == Tarwi::Result::Skipped) { \
                        TARWI_OUTPUT("Skipped " TARWI_FMT_STRING "."#fname"()", this->name); \
                        ++this->skipped_tests; \
                } else { \
                        TARWI_OUTPUT(TARWI_FMT_STRING "."#fname"() failed", this->name); \
                        ++this->failed_tests; \
                } \
        } while (0)

/// Shortcut to skip a test.
#define TARWI_SKIP() \
        do { \
                return Tarwi::Result::Skipped; \
        } while (0)

/// Run the main method of a test module.
/// To be used inside a package.
#define TARWI_RUN_MODULE(mname) \
        do { \
                TARWI_OUTPUT("Running module " TARWI_FMT_STRING "." TARWI_FMT_STRING "...", this->name, mname.name); \
                mname.main(); \
        } while (0)

/// Run the main method of a package.
#define TARWI_RUN_PACKAGE(pname) \
        do { \
                TARWI_OUTPUT("Running package " TARWI_FMT_STRING "...", pname.name); \
                pname.main(); \
        } while (0)

/// Set the name of a module or a package.
#define TARWI_SET_NAME(xname) \
        public: const char *name = xname

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
                        TARWI_OUTPUT("Executed all tests from package " TARWI_FMT_STRING ":", name); \
                        TARWI_OUTPUT("Results: " TARWI_FMT_INTEGER " successfull, " TARWI_FMT_INTEGER " failed and " TARWI_FMT_INTEGER " skipped tests", successfull, failed, skipped); \
                } while (0)

namespace Tarwi
{
        // --------------------------------- Package ---------------------------------
        class Package
        {
        public:
                virtual void main()
                {}
        };

        // --------------------------------- Module ---------------------------------
        class Module
        {
        public:
                int successfull_tests = 0;
                int failed_tests = 0;
                int skipped_tests = 0;

                virtual void main()
                {}
        };

        // --------------------------------- Result ---------------------------------
        enum class Result
        {
                Failed,
                Success,
                Skipped
        };
} // namespace Tarwi