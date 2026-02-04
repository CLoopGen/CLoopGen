#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern int16_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolling by 2
    for (; src + sizeof(int16_t)*2 <= src_end; xdat += 2) {
        tmp = *(const int16_t *)(src);
        src += sizeof(int16_t);
        xdat[0] = (FFTSample)tmp;

        tmp = *(const int16_t *)(src);
        src += sizeof(int16_t);
        xdat[1] = (FFTSample)tmp;
    }
    // Handle remaining element if any
    if (src < src_end) {
        tmp = *(const int16_t *)src;
        src += sizeof(int16_t);
        *xdat = (FFTSample)tmp;
    }
}
