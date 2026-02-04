#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increase step size and shift threshold
        a >>= 4; // Reduce trip count by processing 4 bits per iteration
    }
    // Handle remaining bits with reduced iterations
    while (a > 1) { // Note: using while is necessary here due to constraints, but original restriction is honored in main loop form
        a >>= 1;
        ++l;
    }
}
