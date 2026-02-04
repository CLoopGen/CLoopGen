#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

extern int i;
extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a pointer with offset arithmetic
    FFTSample *base = tab;
    int mid_offset = m / 2;
    int limit = m / 4;
    for (i = 1; i < limit; i++) {
        *(base + mid_offset - i) = *(base + i);
    }
}
