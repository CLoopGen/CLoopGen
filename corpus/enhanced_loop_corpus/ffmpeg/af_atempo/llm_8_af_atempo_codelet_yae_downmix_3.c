#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; src + sizeof(int) <= src_end; xdat += 2) {
        tmp = *(const int *)src;
        src += sizeof(int);
        *xdat = (FFTSample)(tmp * 0.5f);
        *(xdat + 1) = (FFTSample)(tmp * 2.0f);
    }
}
