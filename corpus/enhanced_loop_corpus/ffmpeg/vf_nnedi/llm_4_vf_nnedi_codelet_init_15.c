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
for (j = 0; j < 4; ++j) {
    double cmean = 0.0;
    int index = j * 48;
    for (k = 0; k < 48; ++k) {
        cmean += bdata[index + k];
    }
    mean[j] = cmean / 48.0;
}
}
