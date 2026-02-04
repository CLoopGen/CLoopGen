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
    double prev_tmp = 0.0;
    for (; src < src_end; xdat++, prev_tmp = tmp) {
        tmp = *(const double *)src + prev_tmp; // Introduce WAW and RAW dependency: current tmp depends on previous iteration's tmp
        src += sizeof(double);
        *xdat = (FFTSample)tmp - (FFTSample)prev_tmp; // Introduce WAR: use of prev_tmp before potential write in next iteration
    }
}
