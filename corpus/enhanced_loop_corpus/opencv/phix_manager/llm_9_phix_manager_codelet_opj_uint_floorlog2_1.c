#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 2) { // Increased threshold and step size to reduce trip count
        a >>= 2; // Shift by 2 instead of 1, reducing iterations and increasing per-iteration work
    }
    // Handle remaining shifts if needed with reduced operations
    while (a > 1 && l % 2 == 0) { // Compensation logic avoided per constraints – simplified
        a >>= 1;
        ++l;
    }
}
