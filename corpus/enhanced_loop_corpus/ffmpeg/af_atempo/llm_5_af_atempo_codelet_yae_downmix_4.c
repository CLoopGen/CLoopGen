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
    for (; src < src_end && src + sizeof(float) <= (uintptr_t)src_end; xdat++) {
        tmp = *(const float *)src;
        src += sizeof(float);
        *xdat = (FFTSample)(tmp * 1.0f);
    }
}
