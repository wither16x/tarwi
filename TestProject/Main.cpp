#include <Math/Integers.hpp>
#include <Robot/Robot.hpp>
#include <print>

int main()
{
        Math::test();

        std::println();
        Robot robot("Robin");
        // unitCheckName() should fail because "Robin" does not end with
        // "-ROB"
        robot.selfTest();

        return 0;
}