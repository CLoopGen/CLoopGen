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
if (dstH > 0) {
    int prevLumDiff = 0, prevChrDiff = 0;
    for (lumY = 0; lumY < dstH; lumY++) {
        int chrY = (int64_t)lumY * chrDstH / dstH;
        int baseNextSlice = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
        int candidate = lumFilterPos[lumY] + lumFilterSize - 1;
        int nextSlice = candidate > baseNextSlice ? candidate : baseNextSlice;
        nextSlice = (nextSlice >> chrSubSample) << chrSubSample;

        int lumDiff = nextSlice - lumFilterPos[lumY];
        int chrDiff = (nextSlice >> chrSubSample) - chrFilterPos[chrY];

        *out_lum_size = lumDiff > *out_lum_size ? lumDiff : *out_lum_size;
        *out_chr_size = chrDiff > *out_chr_size ? chrDiff : *out_chr_size;

        prevLumDiff = lumDiff;
        prevChrDiff = chrDiff;
    }
} else {
    *out_lum_size = 0;
    *out_chr_size = 0;
}
}
