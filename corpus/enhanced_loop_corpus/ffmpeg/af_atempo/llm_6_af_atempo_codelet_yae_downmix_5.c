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
    double local_tmp;
    uint8_t *local_src = src;
    FFTSample *local_xdat = xdat;
    for (; local_src < src_end; local_xdat++) {
        local_tmp = *(const double *)local_src;
        local_src += sizeof(double);
        *local_xdat = (FFTSample)local_tmp;
    }
    src = local_src;
    xdat = local_xdat;
}
