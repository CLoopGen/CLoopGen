#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern uint8_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; src + 3 < src_end; xdat += 4) {
        tmp = *(const uint8_t *)src;
        src += sizeof(uint8_t);
        *xdat = (FFTSample)tmp;
        *(xdat + 1) = (FFTSample)tmp * 0.5f;
        *(xdat + 2) = (FFTSample)tmp * 0.75f;
        *(xdat + 3) = (FFTSample)tmp * 1.25f;
        src += sizeof(uint8_t) * 3;
    }
}
