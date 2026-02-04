#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long long MagickSizeType;

extern MagickSizeType *bytes_per_line;
extern  unsigned char *p;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2)
    // This reduces trip count by half but increases operations per iteration
    ssize_t limit = ((ssize_t)*bytes_per_line) & ~1;  // Round down to even
    for (i = 0; i < limit; i += 2) {
        // First byte
        *q++ = (*p >> 4) & 255;
        *q++ = (*p & 15);
        p++;
        // Second byte (unrolled)
        *q++ = (*p >> 4) & 255;
        *q++ = (*p & 15);
        p++;
    }
    // Handle leftover byte if original count was odd
    if (((ssize_t)*bytes_per_line) % 2 == 1) {
        *q++ = (*p >> 4) & 255;
        *q++ = (*p & 15);
        p++;
    }
}
