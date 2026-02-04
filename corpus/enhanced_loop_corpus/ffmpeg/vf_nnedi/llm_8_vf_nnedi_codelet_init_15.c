#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bdata;
extern int j;
extern int k;
extern double mean[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    double cmean = 0.;
    for (k = 0; k < 96; k++)
        cmean += bdata[j * 96 + k];
    mean[j] = cmean / 96.;
}
}
