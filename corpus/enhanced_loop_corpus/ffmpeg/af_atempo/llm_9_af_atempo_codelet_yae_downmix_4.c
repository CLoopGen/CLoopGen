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
    for (int i = 0; src < src_end && i < 1000; i++) {
        tmp = *(const float *)src;
        src += sizeof(float);
        *xdat++ = (FFTSample)(tmp + tmp * 0.1f - 0.05f);
    }
}
