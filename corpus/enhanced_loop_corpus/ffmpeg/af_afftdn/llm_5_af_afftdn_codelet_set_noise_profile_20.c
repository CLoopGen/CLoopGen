#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < 15; m++) {
        if (sample_noise[m] >= 0.0) {
            temp[m] = sample_noise[m];
        } else {
            temp[m] = 0.0;
        }
    }
}
