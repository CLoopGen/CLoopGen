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
    // Eliminate loop-carried dependencies and restructure data access to expose parallelism
    int temp_lum_size = *out_lum_size;
    int temp_chr_size = *out_chr_size;

    for (lumY = 0; lumY < dstH; lumY++) {
        int chrY = (int64_t)lumY * chrDstH / dstH;
        int filterBoundLum = lumFilterPos[lumY] + lumFilterSize - 1;
        int filterBoundChr = (chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample;
        int nextSlice = (filterBoundLum > filterBoundChr) ? filterBoundLum : filterBoundChr;

        nextSlice >>= chrSubSample;
        nextSlice <<= chrSubSample;

        // Remove write-after-write (WAW) hazard by using temporaries
        int candidate_lum = nextSlice - lumFilterPos[lumY];
        int candidate_chr = (nextSlice >> chrSubSample) - chrFilterPos[chrY];

        if (candidate_lum > temp_lum_size) {
            temp_lum_size = candidate_lum;
        }
        if (candidate_chr > temp_chr_size) {
            temp_chr_size = candidate_chr;
        }
    }

    // Final write-back outside the loop (eliminates intra-loop memory dependencies)
    *out_lum_size = temp_lum_size;
    *out_chr_size = temp_chr_size;
}
