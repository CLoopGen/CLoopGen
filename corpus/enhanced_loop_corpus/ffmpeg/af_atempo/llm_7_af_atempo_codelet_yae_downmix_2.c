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
    int16_t local_tmp;
    FFTSample local_xdat;
    ptrdiff_t offset = 0;
    for (; src + offset < src_end; offset += sizeof(int16_t), xdat++) {
        local_tmp = *(const int16_t *)(src + offset);
        local_xdat = (FFTSample)local_tmp;
        *xdat = local_xdat;
    }
}
