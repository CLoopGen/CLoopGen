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
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (order > 0) {
    for (i = 0; i < order; i += 2) {
        int i1 = i;
        int i2 = i + 1;
        c->gain += p[i1][0];
        c->cy[i1] = (-p[i1][0] * p[order][0] + -p[i1][1] * p[order][1]) / (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
        if (i2 < order) {
            c->gain += p[i2][0];
            c->cy[i2] = (-p[i2][0] * p[order][0] + -p[i2][1] * p[order][1]) / (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
        }
    }
}
}
