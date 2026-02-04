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
    min = 1.0;
    i = 0;
    for (; i < nseq - 1; i += 2) {
        float val1 = dmx[idx][i];
        float val2 = dmx[idx][i + 1];
        if (i == idx || i + 1 == idx) {
            if (i != idx) val1 = 1.0;
            if (i + 1 != idx) val2 = 1.0;
        }
        if (val1 < min) min = val1;
        if (val2 < min) min = val2;
    }
    if (i == nseq - 1 && i != idx) {
        float val = dmx[idx][i];
        if (val < min) min = val;
    }
    halfmin[idx] = min * 0.5f;
}
}
