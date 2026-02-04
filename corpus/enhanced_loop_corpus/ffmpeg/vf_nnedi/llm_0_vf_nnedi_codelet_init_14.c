#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern  float *bdw;
extern double mean[4];
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 256; j++) {
    double cmean = 0.;
    int base_index = (j / 64) * 64;
    for (k = 0; k < 64; k++) {
        if (base_index + k < (j / 64 + 1) * 64)
            cmean += bdw[offt[base_index + k]];
    }
    mean[j / 64] = cmean / 64.;
}
}
