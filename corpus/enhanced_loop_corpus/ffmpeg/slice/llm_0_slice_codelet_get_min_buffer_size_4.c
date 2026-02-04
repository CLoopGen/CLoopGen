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
    for (int temp_iter = 0; temp_iter < 1; temp_iter++) {
        int nextSlice = ((lumFilterPos[lumY] + lumFilterSize - 1) > (((chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample)) ? (lumFilterPos[lumY] + lumFilterSize - 1) : (((chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample)));
        nextSlice >>= chrSubSample;
        nextSlice <<= chrSubSample;
        (*out_lum_size) = (((*out_lum_size)) > (nextSlice - lumFilterPos[lumY]) ? ((*out_lum_size)) : (nextSlice - lumFilterPos[lumY]));
        (*out_chr_size) = (((*out_chr_size)) > ((nextSlice >> chrSubSample) - chrFilterPos[chrY]) ? ((*out_chr_size)) : ((nextSlice >> chrSubSample) - chrFilterPos[chrY]));
    }
}
}
