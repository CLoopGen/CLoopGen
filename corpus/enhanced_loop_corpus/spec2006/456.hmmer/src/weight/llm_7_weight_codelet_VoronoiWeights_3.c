#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (itscale == 0) return;
    float inv_scale = 1.0f / (float)itscale;
    for (idx = nseq - 1; idx >= 0; idx--)
        wgt[idx] *= inv_scale;
}
