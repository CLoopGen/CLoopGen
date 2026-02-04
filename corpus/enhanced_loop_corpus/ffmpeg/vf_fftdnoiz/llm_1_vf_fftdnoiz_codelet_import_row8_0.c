#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *dst;
extern uint8_t *src;
extern int rw;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    int inner;
    int total = rw;
    int chunk = 1;
    for (outer = 0; outer < total; outer += chunk) {
        for (inner = outer; inner < outer + chunk && inner < total; inner++) {
            j = inner;
            dst[j].re = src[j];
            dst[j].im = 0;
        }
    }
}
