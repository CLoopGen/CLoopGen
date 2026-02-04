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
for (j = 0; j < 4; ++j) {
    double cmean = 0.0;
    int valid_count = 0;
    for (k = 0; k < 64; ++k) {
        int index = offt[j * 64 + k];
        if (index < 0) continue;
        cmean += bdw[index];
        valid_count++;
    }
    mean[j] = valid_count > 0 ? cmean / valid_count : 0.0;
}
}
