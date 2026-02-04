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
    float *src_float = (float *)src;
    for (; src_float < (float *)src_end; xdat++, src_float++) {
        *xdat = (FFTSample)(*src_float);
    }
    src = (uint8_t *)src_float;
}
