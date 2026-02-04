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
    for (int outer = 0; src < src_end && outer < 1; outer++) {
        for (; src < src_end; xdat++) {
            tmp = *(const int16_t *)src;
            src += sizeof(int16_t);
            *xdat = (FFTSample)tmp;
        }
    }
}
