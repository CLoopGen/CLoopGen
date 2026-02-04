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
    // Variant 2: Indirect memory access using index remapping via a lookup table
    // Simulate indirect access by reversing the iteration order (reverse indexing)
    int idx[31];
    for (int temp_i = 0; temp_i < order; temp_i++) {
        idx[temp_i] = order - 1 - temp_i; // reverse mapping
    }
    for (i = 0; i < order; i++) {
        int mapped_i = idx[i]; // indirect access through index array
        c->gain += p[mapped_i][0];
        c->cy[mapped_i] = (-p[mapped_i][0] * p[order][0] - p[mapped_i][1] * p[order][1]) / 
                          (p[order][0] * p[order][0] + p[order][1] * p[order][1]);
    }
}
