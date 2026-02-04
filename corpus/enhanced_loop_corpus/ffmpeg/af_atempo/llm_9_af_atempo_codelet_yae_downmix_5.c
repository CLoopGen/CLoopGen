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
    for (int i = 0; src < src_end && i < 1000; i++, src += sizeof(double), xdat++) {
        tmp = *(const double *)src;
        *xdat = (FFTSample)(tmp + tmp * 0.1 - 0.05);
    }
}
