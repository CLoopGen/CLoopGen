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
    int prev_lumY = 0;
    for (lumY = 0; lumY < dstH; lumY++) {
        int chrY = (int64_t)lumY * chrDstH / dstH;
        int baseSlice = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
        int candidateSlice = lumFilterPos[lumY] + lumFilterSize - 1;
        int nextSlice = (candidateSlice > baseSlice) ? candidateSlice : baseSlice;
        nextSlice >>= chrSubSample;
        nextSlice <<= chrSubSample;

        // Introduce WAW dependency: use previous iteration's result to influence current update
        int delta_lum = nextSlice - lumFilterPos[lumY];
        int delta_chr = (nextSlice >> chrSubSample) - chrFilterPos[chrY];

        if (prev_lumY > 0) {
            // Create artificial loop-carried dependence: scale current contribution based on prior lumY
            delta_lum += ((*out_lum_size) > 0) ? (prev_lumY % 3) : 0;
            delta_chr += ((*out_chr_size) > 0) ? ((prev_lumY + 1) % 2) : 0;
        }

        (*out_lum_size) = ((*out_lum_size) > delta_lum) ? (*out_lum_size) : delta_lum;
        (*out_chr_size) = ((*out_chr_size) > delta_chr) ? (*out_chr_size) : delta_chr;

        prev_lumY = lumY; // Maintain state for next iteration (loop-carried dependency)
    }
}
