#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < 15; m += 3) {
        temp[m] = sample_noise[m];
        if (m + 1 < 15) temp[m + 1] = sample_noise[m + 1];
        if (m + 2 < 15) temp[m + 2] = sample_noise[m + 2];
    }
}
