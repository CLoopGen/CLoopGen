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
    for (i = 1; i < (order >> 1) + 1; i++) {
        int index = i - 1;
        if (index >= 0 && c->cx[index] != 0) {
            c->cx[i] = c->cx[index] * (order - i + 1LL) / i;
        } else {
            c->cx[i] = c->gain * i;
        }
    }
}
