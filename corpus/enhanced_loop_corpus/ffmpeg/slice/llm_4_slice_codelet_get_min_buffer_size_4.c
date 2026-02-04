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
    int nextSlice = (lumFilterPos[lumY] + lumFilterSize - 1) << chrSubSample;
    int chrEnd = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
    if (chrEnd > nextSlice) {
        nextSlice = chrEnd;
    }
    nextSlice >>= chrSubSample;
    nextSlice <<= chrSubSample;
    int lumDiff = nextSlice - lumFilterPos[lumY];
    int chrDiff = (nextSlice >> chrSubSample) - chrFilterPos[chrY];
    if (lumDiff > *out_lum_size) {
        *out_lum_size = lumDiff;
    }
    if (chrDiff > *out_chr_size) {
        *out_chr_size = chrDiff;
    }
}
}
