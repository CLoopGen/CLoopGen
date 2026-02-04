#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increase effective trip count by processing in chunks
        a >>= 4; // Shift by 4 bits per iteration instead of 1, reducing total iterations but increasing per-iteration work
    }
    // Handle remaining shifts if needed (residual phase with finer control)
    while (a > 1 && l % 4 != 0) { // Note: using while only for cleanup, not primary loop
        a >>= 1;
        ++l;
    }
}
