#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct FFIIRFilterCoeffs {
    int order;
    float gain;
    int *cx;
    float *cy;
};


extern struct FFIIRFilterCoeffs *c;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_cx;
    for (i = 1; i < (order >> 1) + 1; i++) {
        temp_cx = c->cx[i - 1] * (order - i + 1LL) / i;
        c->cx[i] = temp_cx;
    }
}
