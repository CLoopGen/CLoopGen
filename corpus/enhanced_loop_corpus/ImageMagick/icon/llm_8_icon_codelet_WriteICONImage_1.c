#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded trip count and additional arithmetic operations
    ssize_t limit = ((ssize_t)1UL << bits_per_pixel) * 4;
    for (; i < limit; i += 4) {
        *q++ = (unsigned char)(0 + (i & 1));
        *q++ = (unsigned char)(0 + ((i >> 1) & 1));
        *q++ = (unsigned char)(0 + ((i >> 2) & 1));
        *q++ = (unsigned char)(0 + ((i >> 3) & 1));
    }
}
