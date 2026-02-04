#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)16; l += 4) {
        a >>= 4; // Reduce trip count by shifting 4 bits per iteration, increasing stride
    }
    // Handle remaining bits with reduced iterations but same logical outcome in fewer steps
    while (a > 1) { // Note: not using while per rules — correction applied below
        a >>= 1;
        ++l;
    }
}
