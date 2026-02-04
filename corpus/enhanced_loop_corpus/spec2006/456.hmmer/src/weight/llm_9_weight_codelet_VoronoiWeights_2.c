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
for (idx = 0; idx < nseq; idx += 2) {
    float min0 = 1.0, min1 = 1.0;
    int upper_bound = (idx + 1 < nseq) ? nseq : idx + 1;
    for (i = 0; i < upper_bound; i++) {
        if (i != idx && dmx[idx][i] < min0)
            min0 = dmx[idx][i];
        if (idx + 1 < nseq && i != idx + 1 && dmx[idx + 1][i] < min1)
            min1 = dmx[idx + 1][i];
    }
    halfmin[idx] = min0 / 2.0;
    if (idx + 1 < nseq)
        halfmin[idx + 1] = min1 / 2.0;
}
}
