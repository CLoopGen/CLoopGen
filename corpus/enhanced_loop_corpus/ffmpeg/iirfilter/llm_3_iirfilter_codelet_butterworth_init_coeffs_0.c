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
    int *indices = (int*)alloca(sizeof(int) * ((order >> 1) + 1));
    int limit = (order >> 1) + 1;
    // Create indirect access pattern: reverse order of traversal
    for (int j = 0; j < limit; j++) {
        indices[j] = limit - 1 - j;
    }
    for (int j = 0; j < limit; j++) {
        i = indices[j];
        if (i > 0) {
            c->cx[i] = c->cx[i - 1] * (order - i + 1LL) / i;
        }
    }
}
