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
    double cmean = 0.;
    int flat_idx = 0;
    for (j = 0; j < 4; j++) {
        cmean = 0.;
        for (int offset = 0; offset < 48; offset++) {
            cmean += bdata[flat_idx + offset];
        }
        mean[j] = cmean / 48.;
        flat_idx += 48;
    }
}
