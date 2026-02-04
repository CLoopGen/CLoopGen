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
    float temp_gain = c->gain;
    for (i = 0; i < order; i++) {
        temp_gain += p[i][0];
        c->cy[i] = (-p[i][0] * p[order][0] - p[i][1] * p[order][1]) / (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
    }
    c->gain = temp_gain;
}
