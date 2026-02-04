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
for (idx = 0; idx < nseq; idx++) {
    min = 1.;
    for (i = 0; i < nseq; i++) {
        if (i == idx) {
            continue;
        }
        min = (dmx[idx][i] < min) ? dmx[idx][i] : min;
    }
    halfmin[idx] = min * 0.5f;
}
}
