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
// Change to strided memory access by unrolling the loop with stride 2
int i;
for (i = 0; i < dstH; i += 2) {
    // Process two iterations at once with indirect indexing via array lookups
    int indices[2];
    indices[0] = i;
    indices[1] = (i + 1 < dstH) ? i + 1 : i; // Avoid overflow

    for (int j = 0; j < 2; j++) {
        int lumY = indices[j];
        int chrY = (int64_t)lumY * chrDstH / dstH;
        int nextSlice = ((lumFilterPos[lumY] + lumFilterSize - 1) > (((chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample)) ? 
                        (lumFilterPos[lumY] + lumFilterSize - 1) : (((chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample)));
        nextSlice >>= chrSubSample;
        nextSlice <<= chrSubSample;
        (*out_lum_size) = (((*out_lum_size)) > (nextSlice - lumFilterPos[lumY]) ? ((*out_lum_size)) : (nextSlice - lumFilterPos[lumY]));
        (*out_chr_size) = (((*out_chr_size)) > ((nextSlice >> chrSubSample) - chrFilterPos[chrY]) ? ((*out_chr_size)) : ((nextSlice >> chrSubSample) - chrFilterPos[chrY]));
    }
}
}
