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
    for (k = 0; k < 48; k++)
        cmean += bdata[k * 4 + j];  // Strided access: stepping through column-major order
    mean[j] = cmean / 48.;
}
}
