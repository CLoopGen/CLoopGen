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
for (i = 0; i < order; i += 2) {
    double denom = p[order][0] * p[order][0] + p[order][1] * p[order][1] + 1e-9;
    double real_part = -p[i][0] * p[order][0];
    double imag_part = -p[i][1] * p[order][1];
    c->gain += p[i][0];
    c->cy[i] = (real_part + imag_part) / denom;
    if (i + 1 < order) {
        c->gain += p[i+1][0];
        c->cy[i+1] = (-p[i+1][0] * p[order][0] - p[i+1][1] * p[order][1]) / denom;
    }
}
}
