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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    // Improves spatial locality by processing two elements at a time if bytes_per_line is even
    ssize_t n = (ssize_t)*bytes_per_line;
    ssize_t limit = n - 1;
    for (i = 0; i < limit; i += 2) {
        // First byte
        *q++ = (*p >> 6) & 3;
        *q++ = (*p >> 4) & 3;
        *q++ = (*p >> 2) & 3;
        *q++ = (*p     ) & 3;
        p++;
        // Second byte
        *q++ = (*p >> 6) & 3;
        *q++ = (*p >> 4) & 3;
        *q++ = (*p >> 2) & 3;
        *q++ = (*p     ) & 3;
        p++;
    }
    // Handle remaining element if bytes_per_line is odd
    if (i < n) {
        *q++ = (*p >> 6) & 3;
        *q++ = (*p >> 4) & 3;
        *q++ = (*p >> 2) & 3;
        *q++ = (*p & 3);
        p++;
    }
}
