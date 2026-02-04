#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_local[15];
    for (int m = 0; m < 15; m++)
        temp_local[m] = sample_noise[m];
    for (int m = 0; m < 15; m++)
        temp[m] = temp_local[m];
}
