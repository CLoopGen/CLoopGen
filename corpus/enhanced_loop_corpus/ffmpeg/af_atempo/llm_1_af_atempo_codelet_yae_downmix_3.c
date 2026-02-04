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
    for (int outer = 0; outer < 1 && src < src_end; outer++) {
        for (; src < src_end; xdat++) {
            tmp = *(const int *)src;
            src += sizeof(int);
            *xdat = (FFTSample)tmp;
        }
    }
}
