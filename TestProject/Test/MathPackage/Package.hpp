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

                TARWI_DISPLAY_RESULTS(
                        integers_module.successfull_tests,
                        integers_module.failed_tests,
                        integers_module.skipped_tests
                );
        }
};