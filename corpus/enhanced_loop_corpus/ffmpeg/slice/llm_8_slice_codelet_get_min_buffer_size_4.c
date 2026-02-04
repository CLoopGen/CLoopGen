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
for (lumY = 0; lumY < dstH; lumY += 2) {
    int chrY = (int64_t)lumY * chrDstH / dstH;
    int nextSlice1 = lumFilterPos[lumY] + lumFilterSize - 1;
    int nextSlice2 = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
    int nextSlice = nextSlice1 > nextSlice2 ? nextSlice1 : nextSlice2;
    nextSlice >>= chrSubSample;
    nextSlice <<= chrSubSample;
    int lumDiff = nextSlice - lumFilterPos[lumY];
    int chrDiff = (nextSlice >> chrSubSample) - chrFilterPos[chrY];
    if (lumDiff > *out_lum_size) *out_lum_size = lumDiff;
    if (chrDiff > *out_chr_size) *out_chr_size = chrDiff;

    if (lumY + 1 < dstH) {
        int chrY2 = (int64_t)(lumY + 1) * chrDstH / dstH;
        int nextSlice1_2 = lumFilterPos[lumY + 1] + lumFilterSize - 1;
        int nextSlice2_2 = (chrFilterPos[chrY2] + chrFilterSize - 1) << chrSubSample;
        int nextSlice_2 = nextSlice1_2 > nextSlice2_2 ? nextSlice1_2 : nextSlice2_2;
        nextSlice_2 >>= chrSubSample;
        nextSlice_2 <<= chrSubSample;
        int lumDiff2 = nextSlice_2 - lumFilterPos[lumY + 1];
        int chrDiff2 = (nextSlice_2 >> chrSubSample) - chrFilterPos[chrY2];
        if (lumDiff2 > *out_lum_size) *out_lum_size = lumDiff2;
        if (chrDiff2 > *out_chr_size) *out_chr_size = chrDiff2;
    }
}
}
