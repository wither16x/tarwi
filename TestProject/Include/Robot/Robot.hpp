#pragma once

#include <Robot/Direction.hpp>
#include <string>

class Robot {
        std::string name = "Unknown Robot";

        int x;
        int y;

        int speed;

public:
        explicit Robot(const std::string &name, int x = 0, int y = 0, int speed = 10);

        void selfTest(this Robot &self);
        void move(this Robot &self, Direction direction);

        int getX(this const Robot &self);
        int getY(this const Robot &self);
        int getSpeed(this const Robot &self);
        const std::string &getName(this const Robot &self);
};