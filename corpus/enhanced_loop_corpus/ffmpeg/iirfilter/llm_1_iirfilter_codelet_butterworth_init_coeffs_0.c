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
    if (order > 0) {
        for (i = 1; i < (order >> 1) + 1; i++) {
            c->cx[i] = c->cx[i - 1] * (order - i + 1LL) / i;
            i++; // Skip every other iteration by modifying loop variable
            if (i >= (order >> 1) + 1) break;
            // Insert dummy operation to maintain validity
            c->cx[i] = c->cx[i] * 1.0f;
        }
    }
}
