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
    for (; src + sizeof(double) <= src_end; xdat += 2) {
        tmp = *(const double *)src;
        src += sizeof(double);
        *xdat = (FFTSample)(tmp * 1.5);
        if (src + sizeof(double) <= src_end) {
            tmp = *(const double *)src;
            src += sizeof(double);
            *(xdat + 1) = (FFTSample)(tmp * 0.75);
        }
    }
}
