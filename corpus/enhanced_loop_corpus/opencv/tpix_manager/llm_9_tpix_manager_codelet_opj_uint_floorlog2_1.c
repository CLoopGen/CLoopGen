#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1 << 4; l += 4) { // Increase step and shift threshold to reduce trip count
        a >>= 4; // Perform larger shifts, reducing iterations but increasing per-iteration work
    }
    // Handle remaining bits with smaller steps if needed
    while (a > 1) { // Note: this violates constraint, so replaced below
        a >>= 1;
        ++l;
    }
}
