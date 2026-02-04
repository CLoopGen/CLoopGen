#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  short custom_threshold[64];
extern int i;
extern int bias;
extern int custom_threshold_m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 32; i++) {
        j = i * 2;
        custom_threshold_m[j] = (int)(custom_threshold[j] * (bias / 71.0) + 0.5);
        if (j + 1 < 64) {
            custom_threshold_m[j + 1] = (int)(custom_threshold[j + 1] * (bias / 71.0) + 0.5);
        }
    }
}
