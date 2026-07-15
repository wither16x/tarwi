#include <Tarwi.hpp>
#include <RobotPackage/Package.hpp>
#include <Robot/Robot.hpp>
#include <print>

using std::println;
using std::string;

Robot::Robot(const std::string &name, int x, int y, int speed)
        : name(name), x(x), y(y), speed(speed)
{
        println("Hello! My name is {} and I am a robot!", this->name);
}

void Robot::selfTest(this Robot &self)
{
        RobotPackage robot_package(self);
        TARWI_RUN_PACKAGE(robot_package);
}

void Robot::move(this Robot &self, Direction direction)
{
        switch (direction)
        {
        case Direction::Left:
                --self.x;
                break;

        case Direction::Right:
                ++self.x;
                break;

        case Direction::Up:
                ++self.y;
                break;

        case Direction::Down:
                --self.y;
                break;
        }
}

int Robot::getX(this const Robot &self)
{
        return self.x;
}

int Robot::getY(this const Robot &self)
{
        return self.y;
}

int Robot::getSpeed(this const Robot &self)
{
        return self.speed;
}

const string &Robot::getName(this const Robot &self)
{
        return self.name;
}