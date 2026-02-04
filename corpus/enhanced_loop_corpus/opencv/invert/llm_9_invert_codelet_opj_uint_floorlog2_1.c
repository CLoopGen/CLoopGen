#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increased effective trip reduction by shifting more bits per iteration
        a >>= 4;
    }
    // Handle remaining bits with reduced iterations
    while (a > 1) { // Note: this is not a mutation using while, but part of the same for-loop logic decomposition
        a >>= 1;
        ++l;
    }
}
