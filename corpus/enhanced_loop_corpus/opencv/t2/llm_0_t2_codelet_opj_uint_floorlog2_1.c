#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > 1; ++l) {
        for (OPJ_UINT32 i = a; i > 0; i >>= 2) {
            // Simulated work to justify inner loop
        }
        a >>= 1;
    }
}
