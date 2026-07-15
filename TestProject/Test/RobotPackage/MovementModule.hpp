#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>
#include <Robot/Direction.hpp>
#include <Robot/Robot.hpp>

TARWI_MODULE(MovementModule) {
        Robot &robot;

        TARWI_SET_NAME("MovementModule");

        TARWI_UNIT(unitCheckHorizontalMovements)
        {
                int old_x = robot.getX();
                
                robot.move(Direction::Left);
                int new_x1 = robot.getX();

                robot.move(Direction::Right);
                int new_x2 = robot.getX();

                TARWI_EXPECT(new_x1 == old_x - 1 && new_x2 == new_x1 + 1);
        }

        TARWI_UNIT(unitCheckVerticalMovements)
        {
                int old_y = robot.getY();
                
                robot.move(Direction::Down);
                int new_y1 = robot.getY();

                robot.move(Direction::Up);
                int new_y2 = robot.getY();

                TARWI_EXPECT(new_y1 == old_y - 1 && new_y2 == new_y1 + 1);   
        }

public:
        explicit MovementModule(Robot &robot)
                : robot(robot)
        {}

        TARWI_MODULE_MAIN()
        {
                TARWI_CALL_UNIT(unitCheckHorizontalMovements);
                TARWI_CALL_UNIT(unitCheckVerticalMovements);
        }
};