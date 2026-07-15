#pragma once

#if defined(TARWI_OUTPUT)
        #undef TARWI_OUTPUT
        #include <cstdio>
        #define TARWI_OUTPUT(...) do { printf(__VA_ARGS__); } while (0)
#endif