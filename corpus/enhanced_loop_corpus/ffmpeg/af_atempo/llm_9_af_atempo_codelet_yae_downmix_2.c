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
    for (int stride = 2; src + sizeof(int16_t) * stride <= src_end; xdat++, src += sizeof(int16_t) * stride) {
        tmp = *(const int16_t *)(src + sizeof(int16_t)); // Skip first sample, process every second
        *xdat = (FFTSample)tmp;
    }
}
