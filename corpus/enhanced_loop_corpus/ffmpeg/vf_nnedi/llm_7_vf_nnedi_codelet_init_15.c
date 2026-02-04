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
double temp_mean[4] = {0.};
for (k = 0; k < 48; k++) {
    for (j = 0; j < 4; j++) {
        temp_mean[j] += bdata[j * 48 + k] / 48.;
    }
}
for (j = 0; j < 4; j++) {
    mean[j] = temp_mean[j];
}
}
