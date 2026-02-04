#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive sequential access using pointer arithmetic
    // Restructure array accesses to use increasing pointers for spatial locality
    FFTSample *out = output;
    FFTSample *mirror_low = out + n2 - 1; // starts at n2-1, goes backward
    FFTSample *mirror_high = out + n2;     // starts at n2, goes forward
    FFTSample *tail = out + n - 1;         // tail end of output, goes backward

    for (k = 0; k < n4; k++) {
        *out++ = -*mirror_low--;
        *tail-- = *mirror_high++;
    }
}
