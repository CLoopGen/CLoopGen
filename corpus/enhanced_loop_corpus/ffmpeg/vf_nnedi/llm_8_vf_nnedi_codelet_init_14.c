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
for (j = 0; j < 4; j++) {
    double cmean = 0.;
    int base_index = j * 64;
    for (k = 0; k < 32; k++) {
        cmean += bdw[offt[base_index + k]] + bdw[offt[base_index + k + 32]];
    }
    mean[j] = cmean / 64.;
}
}
