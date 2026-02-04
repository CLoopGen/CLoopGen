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
    // Variant 2: Strided memory access pattern
    // Access every second byte in p, then handle remainder.
    // This creates a strided access pattern with stride 2.
    // Each iteration processes one byte but skips the next.
    
    ssize_t n = (ssize_t)*bytes_per_line;
    ssize_t step = 2;
    ssize_t limit = n - (n % step);  // Round down to multiple of stride

    // Strided access: process only even indices
    for (i = 0; i < limit; i += step) {
        unsigned char val = p[i];
        *q++ = (val >> 7) & 1;
        *q++ = (val >> 6) & 1;
        *q++ = (val >> 5) & 1;
        *q++ = (val >> 4) & 1;
        *q++ = (val >> 3) & 1;
        *q++ = (val >> 2) & 1;
        *q++ = (val >> 1) & 1;
        *q++ = val & 1;
    }

    // Handle remaining bytes if any (i.e., when n is odd)
    for (; i < n; i++) {
        unsigned char val = p[i];
        *q++ = (val >> 7) & 1;
        *q++ = (val >> 6) & 1;
        *q++ = (val >> 5) & 1;
        *q++ = (val >> 4) & 1;
        *q++ = (val >> 3) & 1;
        *q++ = (val >> 2) & 1;
        *q++ = (val >> 1) & 1;
        *q++ = val & 1;
    }
}
