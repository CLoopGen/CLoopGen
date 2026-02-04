#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; src < src_end; ) {
        for (int i = 0; i < 1 && src < src_end; i++, xdat++) {
            tmp = *(const double *)src;
            src += sizeof(double);
            *xdat = (FFTSample)tmp;
        }
    }
}
