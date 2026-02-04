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
    FFTSample temp_val;
    ptrdiff_t offset = 0;
    for (; src + offset < src_end; offset += sizeof(uint8_t)) {
        tmp = *(const uint8_t *)(src + offset);
        temp_val = (FFTSample)tmp;
        xdat[offset] = temp_val;
    }
}
