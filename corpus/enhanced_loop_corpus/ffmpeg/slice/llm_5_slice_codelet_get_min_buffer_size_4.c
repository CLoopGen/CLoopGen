#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *out_lum_size;
extern int *out_chr_size;
extern int lumY;
extern int dstH;
extern int chrDstH;
extern int *lumFilterPos;
extern int *chrFilterPos;
extern int lumFilterSize;
extern int chrFilterSize;
extern int chrSubSample;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (lumY = 0; lumY < dstH; lumY++) {
    int chrY = (int64_t)lumY * chrDstH / dstH;
    int lumEnd = lumFilterPos[lumY] + lumFilterSize - 1;
    int chrEnd = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
    int nextSlice = lumEnd << chrSubSample;

    // Introduce early skip condition based on filter size bounds
    if (lumEnd < 0 || chrY >= chrDstH) {
        continue;
    }

    if ((nextSlice >> chrSubSample) < chrEnd) {
        nextSlice = chrEnd;
    }

    nextSlice >>= chrSubSample;
    nextSlice <<= chrSubSample;

    int candidateLum = nextSlice - lumFilterPos[lumY];
    int candidateChr = (nextSlice >> chrSubSample) - chrFilterPos[chrY];

    // Replace ternary-based max with conditional assignments
    if (candidateLum > *out_lum_size) {
        *out_lum_size = candidateLum;
    }
    if (candidateChr > *out_chr_size) {
        *out_chr_size = candidateChr;
    }
}
}
