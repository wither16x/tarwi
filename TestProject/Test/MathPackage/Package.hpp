#pragma once

#include <Tarwi.hpp>
#include <MathPackage/IntegersModule.hpp>

TARWI_PACKAGE(MathPackage) {
        TARWI_SET_NAME("MathPackage");

        IntegersModule integers_module;

public:
        TARWI_PACKAGE_MAIN()
        {
                TARWI_RUN_MODULE(integers_module);

                int total_successfull_tests = integers_module.successfull_tests;
                int total_failed_tests = integers_module.failed_tests;
                int total_skipped_tests = integers_module.skipped_tests;

                TARWI_OUTPUT("Executed all tests from package %s:\n", name);
                TARWI_OUTPUT("Results: %d successfull, %d failed and %d skipped tests\n", total_successfull_tests, total_failed_tests, total_skipped_tests);
        }
};