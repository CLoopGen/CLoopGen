#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > 1 && l < 32; ++l) {
        a >>= 1;
        for (OPJ_UINT32 j = 0; j < 1; ++j) {
            // Artificial inner work to increase nesting depth
            continue;
        }
    }
}
