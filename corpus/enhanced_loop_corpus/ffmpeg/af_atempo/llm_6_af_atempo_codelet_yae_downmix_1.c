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
    uint8_t local_tmp;
    FFTSample *xdat_orig = xdat;
    for (; src < src_end; src += sizeof(uint8_t), xdat++) {
        local_tmp = *(const uint8_t *)src;
        *xdat = (FFTSample)local_tmp;
    }
    xdat = xdat_orig;
    for (; src < src_end; src += sizeof(uint8_t), xdat++) {
        tmp = *(const uint8_t *)src;
        *xdat = (FFTSample)tmp;
    }
}
