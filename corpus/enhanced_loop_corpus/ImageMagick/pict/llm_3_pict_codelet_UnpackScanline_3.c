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
    // Variant 2: Strided memory access - process every second byte first, then the odd-positioned ones
    // This creates a non-consecutive access pattern, potentially useful in SIMD or cache partitioning contexts
    ssize_t n = (ssize_t)*bytes_per_line;
    ssize_t stride = 2;
    
    // Process even indices: 0, 2, 4, ...
    for (i = 0; i < n; i += stride) {
        unsigned char temp = p[i];
        *q++ = (temp >> 6) & 3;
        *q++ = (temp >> 4) & 3;
        *q++ = (temp >> 2) & 3;
        *q++ = (temp     ) & 3;
    }
    // Process odd indices: 1, 3, 5, ...
    for (i = 1; i < n; i += stride) {
        unsigned char temp = p[i];
        *q++ = (temp >> 6) & 3;
        *q++ = (temp >> 4) & 3;
        *q++ = (temp >> 2) & 3;
        *q++ = (temp     ) & 3;
    }
    // Update global p to point past the last processed byte
    p += n;
}
