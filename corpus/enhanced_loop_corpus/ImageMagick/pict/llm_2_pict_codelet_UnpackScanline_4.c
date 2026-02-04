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
    // Variant 1: Consecutive memory access with reversed bit extraction order
    // Instead of processing bits from MSB to LSB, process from LSB to MSB consecutively.
    // Also unroll the loop partially and access p[i] directly for better locality.

    ssize_t n = (ssize_t)*bytes_per_line;
    for (i = 0; i < n; i++) {
        unsigned char val = p[i];
        *q++ = val & 1;
        *q++ = (val >> 1) & 1;
        *q++ = (val >> 2) & 1;
        *q++ = (val >> 3) & 1;
        *q++ = (val >> 4) & 1;
        *q++ = (val >> 5) & 1;
        *q++ = (val >> 6) & 1;
        *q++ = (val >> 7) & 1;
    }
}
