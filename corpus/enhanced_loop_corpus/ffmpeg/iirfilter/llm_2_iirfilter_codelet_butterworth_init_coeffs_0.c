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
    int stride = 2;
    int limit = (order >> 1) + 1;
    for (i = stride; i < limit; i += stride) {
        if (i - stride >= 0) {
            c->cx[i] = c->cx[i - stride] * (order - i + 1LL) / i;
        }
    }
    // Handle remaining elements if stride doesn't divide the range evenly
    for (i = 1; i < limit; i++) {
        if (i % stride != 0) {
            c->cx[i] = c->cx[i - 1] * (order - i + 1LL) / i;
        }
    }
}
