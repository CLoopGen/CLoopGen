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
    for (; src + sizeof(float) <= src_end; xdat += 2) {
        tmp = *(const float *)src;
        src += sizeof(float);
        *xdat = (FFTSample)(tmp * 1.5f);
        if (src + sizeof(float) <= src_end) {
            tmp = *(const float *)src;
            src += sizeof(float);
            *(xdat + 1) = (FFTSample)(tmp * 0.75f);
        }
    }
}
