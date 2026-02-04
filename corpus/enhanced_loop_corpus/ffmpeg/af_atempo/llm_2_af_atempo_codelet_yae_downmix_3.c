#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (; src + sizeof(int) * (stride - 1) < src_end; src += sizeof(int) * stride, xdat++) {
        tmp = *(const int *)(src);
        *xdat = (FFTSample)tmp;
    }
}
