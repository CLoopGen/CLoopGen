#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *orig;
extern int16_t rem[64];
extern int i;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 64; i += 2) {
        rem[i] = dc - (orig[i] << 6);
        if (i + 1 < 64) {
            rem[i + 1] = dc - (orig[i + 1] << 6);
        }
    }
}
