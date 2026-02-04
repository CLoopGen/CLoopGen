#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_tmp;
    uint8_t *local_src = src;
    FFTSample *local_xdat = xdat;
    for (; local_src < src_end; local_src += sizeof(float), local_xdat++) {
        local_tmp = *(const float *)local_src;
        *local_xdat = (FFTSample)local_tmp;
    }
    src = local_src;
    xdat = local_xdat;
}
