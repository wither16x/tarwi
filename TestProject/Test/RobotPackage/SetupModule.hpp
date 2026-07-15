#pragma once

#include <Robot/Robot.hpp>
#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

TARWI_MODULE(SetupModule) {
        const Robot &robot;

        TARWI_SET_NAME("SetupModule");

        /// The robot's name must end with -ROB.
        TARWI_UNIT(unitCheckName)
        {
                const std::string &name = this->robot.getName();
                TARWI_EXPECT(name.ends_with("-ROB"));
        }

public:
        explicit SetupModule(const Robot &robot)
                : robot(robot)
        {}

        TARWI_MODULE_MAIN()
        {
                TARWI_CALL_UNIT(unitCheckName);
        }
};