#include <Tarwi.hpp>
#include <Math/Integers.hpp>
#include <MathPackage/Package.hpp>

namespace Math {

void test()
{
        MathPackage test_package;
        TARWI_RUN_PACKAGE(test_package);
}

int add(int a, int b)
{
        return a + b;
}

int sub(int a, int b)
{
        return a - b;
}

int mul(int a, int b)
{
        return a * b;
}

int div(int a, int b)
{
        return a / b;
}

}