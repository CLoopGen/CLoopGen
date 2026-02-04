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
    double cmean1 = 0., cmean2 = 0.;
    for (k = 0; k < 24; k++) {
        cmean1 += bdata[j * 48 + k];
        cmean2 += bdata[j * 48 + k + 24];
    }
    mean[j] = (cmean1 + cmean2) / 48.;
}
}
