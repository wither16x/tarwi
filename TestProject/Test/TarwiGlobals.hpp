#pragma once

#if defined(TARWI_OUTPUT)
        #undef TARWI_OUTPUT
        #include <cstdio>
        #define TARWI_OUTPUT(...) do { printf(__VA_ARGS__); printf("\n"); } while (0)
#endif

#if defined(TARWI_FMT_STRING)
        #undef TARWI_FMT_STRING
        #define TARWI_FMT_STRING "%s"
#endif

#if defined(TARWI_FMT_INTEGER)
        #undef TARWI_FMT_INTEGER
        #define TARWI_FMT_INTEGER "%d"
#endif