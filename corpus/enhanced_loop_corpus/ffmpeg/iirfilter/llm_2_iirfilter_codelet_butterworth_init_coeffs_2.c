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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern changed to process elements i and i+1 with step of 2
    for (i = 0; i < order; i += 2) {
        int j = i;
        if (j < order) {
            c->gain += p[j][0];
            c->cy[j] = (-p[j][0] * p[order][0] - p[j][1] * p[order][1]) / 
                       (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
        }
        j = i + 1;
        if (j < order) {
            c->gain += p[j][0];
            c->cy[j] = (-p[j][0] * p[order][0] - p[j][1] * p[order][1]) / 
                       (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
        }
    }
}
