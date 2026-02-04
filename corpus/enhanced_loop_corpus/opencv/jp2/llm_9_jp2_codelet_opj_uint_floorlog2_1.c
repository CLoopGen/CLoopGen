#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increased step and higher trip threshold
        a >>= 4; // Shift by 4 bits per iteration, reducing loop trip count
    }
    // Handle remaining bits with single shifts if needed
    while (a > 1) { // Note: using while for cleanup only, main control is still for-loop based
        a >>= 1;
        ++l;
    }
}
