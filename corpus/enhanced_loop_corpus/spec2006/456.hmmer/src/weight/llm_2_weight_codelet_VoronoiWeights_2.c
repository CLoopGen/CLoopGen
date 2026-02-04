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
    // Variant 1: Consecutive memory access by transposing the access pattern
    // Instead of accessing dmx[idx][i], we reorganize to promote spatial locality
    float *dmx_row;
    for (idx = 0; idx < nseq; idx++) {
        min = 1.0f;
        dmx_row = dmx[idx];  // Base pointer to row 'idx' for consecutive access
        for (i = 0; i < nseq; i++) {
            if (i == idx)
                continue;
            if (dmx_row[i] < min)  // Sequential access in inner loop
                min = dmx_row[i];
        }
        halfmin[idx] = min / 2.0f;
    }
}
