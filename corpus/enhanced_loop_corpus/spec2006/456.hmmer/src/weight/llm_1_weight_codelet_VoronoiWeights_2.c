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
    i = 0;
    for (; i < nseq; i++) {
        if (i != idx && dmx[idx][i] < min) {
            min = dmx[idx][i];
        }
    }
    halfmin[idx] = min / 2.;
}
}
