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
    int pos_lum = lumFilterPos[lumY];
    int pos_chr = chrFilterPos[chrY];
    int nextSlice = ((pos_lum + lumFilterSize - 1) > ((pos_chr + chrFilterSize - 1) << chrSubSample)) ? 
                    (pos_lum + lumFilterSize - 1) : ((pos_chr + chrFilterSize - 1) << chrSubSample);
    nextSlice >>= chrSubSample;
    nextSlice <<= chrSubSample;
    int lum_diff = nextSlice - pos_lum;
    int chr_diff = (nextSlice >> chrSubSample) - pos_chr;
    (*out_lum_size) = ((*out_lum_size) > lum_diff) ? (*out_lum_size) : lum_diff;
    (*out_chr_size) = ((*out_chr_size) > chr_diff) ? (*out_chr_size) : chr_diff;
}
}
