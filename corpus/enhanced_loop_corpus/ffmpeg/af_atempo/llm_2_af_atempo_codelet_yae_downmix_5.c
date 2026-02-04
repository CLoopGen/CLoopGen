#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by 2 for improved spatial locality
    for (; src + sizeof(double) <= src_end; xdat += 2) {
        tmp = *(const double *)src;
        src += sizeof(double);
        *xdat = (FFTSample)tmp;

        if (src + sizeof(double) > src_end) break;

        tmp = *(const double *)(src);
        src += sizeof(double);
        *(xdat + 1) = (FFTSample)tmp;
    }
    // Handle any remaining element
    if (src < src_end) {
        tmp = *(const double *)src;
        src += sizeof(double);
        *xdat = (FFTSample)tmp;
    }
}
