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
    for (; src < src_end && src + 3*sizeof(int) < src_end; ) {
        tmp = *(const int *)src;
        src += sizeof(int);
        *xdat++ = (FFTSample)tmp;

        tmp = *(const int *)src;
        src += sizeof(int);
        *xdat++ = (FFTSample)(tmp + 1);

        tmp = *(const int *)src;
        src += sizeof(int);
        *xdat++ = (FFTSample)(tmp - 1);

        tmp = *(const int *)src;
        src += sizeof(int);
        *xdat++ = (FFTSample)(tmp * tmp);
    }
}
