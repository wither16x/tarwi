#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>
#include <Math/Integers.hpp>

TARWI_MODULE(IntegersModule) {
        TARWI_SET_NAME("IntegersModule");

        TARWI_UNIT(unitAddition)
        {
                int result = Math::add(3, 4);
                TARWI_EXPECT(result == 7);
        }

        TARWI_UNIT(unitSubstraction)
        {
                int result = Math::sub(5, 8);
                TARWI_EXPECT(result == -3);
        }

        TARWI_UNIT(unitMultiplication)
        {
                int result = Math::mul(4, 2);
                TARWI_EXPECT(result == 8);
        }

        TARWI_UNIT(unitDivision)
        {
                int result = Math::div(10, 2);
                TARWI_EXPECT(result == 5);
        }

        TARWI_MODULE_MAIN()
        {
                TARWI_CALL_UNIT(unitAddition);
                TARWI_CALL_UNIT(unitSubstraction);
                TARWI_CALL_UNIT(unitMultiplication);
                TARWI_CALL_UNIT(unitDivision);
        }
};