#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>
#include <RobotPackage/SetupModule.hpp>
#include <RobotPackage/MovementModule.hpp>

TARWI_PACKAGE(RobotPackage) {
        TARWI_SET_NAME("RobotPackage");

        SetupModule setup_module;
        MovementModule movement_module;

public:
        explicit RobotPackage(Robot &robot)
                : setup_module(robot), movement_module(robot)
        {}

        TARWI_PACKAGE_MAIN()
        {
                TARWI_RUN_MODULE(setup_module);
                TARWI_RUN_MODULE(movement_module);

                int total_successfull_tests = setup_module.successfull_tests + movement_module.successfull_tests;
                int total_failed_tests = setup_module.failed_tests + movement_module.failed_tests;
                int total_skipped_tests = setup_module.skipped_tests + movement_module.skipped_tests;

                TARWI_OUTPUT("Executed all tests from package %s:\n", name);
                TARWI_OUTPUT("Results: %d successfull, %d failed and %d skipped tests\n", total_successfull_tests, total_failed_tests, total_skipped_tests);
        }
};