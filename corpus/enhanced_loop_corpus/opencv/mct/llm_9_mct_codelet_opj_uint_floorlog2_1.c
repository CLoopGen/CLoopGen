#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increased trip condition threshold and step size
        a >>= 4; // Shift by 4 bits per iteration instead of 1, reducing loop trips but increasing per-iteration work
    }
    // Handle remaining shifts if needed (cleanup loop with original logic)
    while (a > 1) {
        a >>= 1;
        ++l;
    }
}
