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
    FFTSample *xdat_orig = xdat;
    for (; src < src_end; ) {
        tmp = *(const int16_t *)src;
        src += sizeof(int16_t);
        *xdat++ = (FFTSample)tmp;
    }
    xdat = xdat_orig + (src - (uint8_t*)0) / sizeof(int16_t); // Reconstruct final xdat value to preserve semantics
}
