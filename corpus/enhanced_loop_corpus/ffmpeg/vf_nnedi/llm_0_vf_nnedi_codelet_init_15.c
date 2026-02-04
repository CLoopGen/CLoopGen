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
    double cmean[4] = {0.};
    for (j = 0; j < 192; j++) {
        int idx = j / 48;
        cmean[idx] += bdata[j];
    }
    for (j = 0; j < 4; j++) {
        mean[j] = cmean[j] / 48.;
    }
}
