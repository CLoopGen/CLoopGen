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

struct FFIIRFilterCoeffs *c;
int order;
int i;
double p[31][2];

void init_vars() {
    order = 30; // Ensures i goes from 0 to 29, within bounds of p[31][2]
    
    c = (struct FFIIRFilterCoeffs*)malloc(sizeof(struct FFIIRFilterCoeffs));
    c->order = order;
    c->gain = 0.0f;
    c->cx = (int*)malloc(order * sizeof(int));
    c->cy = (float*)malloc(order * sizeof(float));

    for (int idx = 0; idx < order + 1; idx++) {
        p[idx][0] = 1.0 + idx * 0.1;
        p[idx][1] = 0.5 + idx * 0.05;
    }

    for (int idx = 0; idx < order; idx++) {
        c->cx[idx] = idx * 2;
        c->cy[idx] = 0.0f;
    }
}