#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second float)
    for (; src + sizeof(float) < src_end; xdat++) {
        tmp = *(const float *)(src);
        src += 2 * sizeof(float);  // Advance by two floats each iteration
        *xdat = (FFTSample)tmp;
    }
}
