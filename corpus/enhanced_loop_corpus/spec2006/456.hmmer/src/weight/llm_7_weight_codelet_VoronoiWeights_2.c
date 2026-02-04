#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float **dmx;
extern float *halfmin;
extern int idx;
extern int i;
extern float min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp_halfmin = (float*)__builtin_alloca(nseq * sizeof(float));
    for (idx = 0; idx < nseq; idx++) {
        float min_val = 1.0;
        for (i = 0; i < nseq; i++) {
            if (i == idx) continue;
            min_val = (dmx[idx][i] < min_val) ? dmx[idx][i] : min_val;
        }
        temp_halfmin[idx] = min_val / 2.0;
    }
    for (idx = 0; idx < nseq; idx++) {
        halfmin[idx] = temp_halfmin[idx];
    }
}
