#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < 5; m++) {
        for (int n = 0; n < 3; n++) {
            temp[m * 3 + n] = sample_noise[m * 3 + n];
        }
    }
}
