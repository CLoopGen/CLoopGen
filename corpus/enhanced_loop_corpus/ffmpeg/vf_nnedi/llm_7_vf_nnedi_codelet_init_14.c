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
double temp_mean[4] = {0.};
for (j = 0; j < 4; j++) {
    for (k = 0; k < 64; k++) {
        int index = j * 64 + k;
        temp_mean[j] += bdw[offt[index]];
    }
}
for (j = 0; j < 4; j++) {
    mean[j] = temp_mean[j] / 64.0;
}
}
