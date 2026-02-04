#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    temp[0] = sample_noise[0];
    for (int m = 1; m < 15; m++) {
        temp[m] = temp[m-1] + (sample_noise[m] - sample_noise[m-1]);
    }
}
