#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified operations and unrolled inner work
    ssize_t limit = ((ssize_t)1UL << (bits_per_pixel - 2)) + 1;
    for (; i < limit; i++) {
        // Unroll and reduce memory writes per iteration but increase arithmetic density
        unsigned char val = (unsigned char)((i * 37) % 256);
        *q++ = val;
        *q++ = val;
        *q++ = val;
        *q++ = val;
    }
}
