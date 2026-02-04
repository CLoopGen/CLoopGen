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
    for (i = 2; i < order; i += 2) {
        if (i < (order >> 1) + 1)
            c->cx[i] = c->cx[i - 1] * (order - i + 1LL) / i;
        if (i + 1 < (order >> 1) + 1)
            c->cx[i + 1] = c->cx[i] * (order - (i + 1) + 1LL) / (i + 1);
    }
}
