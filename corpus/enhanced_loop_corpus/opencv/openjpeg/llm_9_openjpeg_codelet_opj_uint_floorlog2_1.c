#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    l = 0;
    OPJ_UINT32 mask = 1;
    OPJ_UINT32 bit_pos = 0;
    // Increase computational intensity: simulate bit scanning with multiple operations per iteration
    for (OPJ_UINT32 i = 0; i < 32 && bit_pos == 0; ++i) {
        mask = (1U << i);
        if ((a & mask) && a >= (1U << i)) {
            bit_pos = i;
        }
        l += (a >> i) & 1;  // Count set bits up to position i, increasing arithmetic work
    }
    l = (l > 0) ? l - 1 : 0;  // Adjust to match approximate original meaning (log-scale approximation)
}
