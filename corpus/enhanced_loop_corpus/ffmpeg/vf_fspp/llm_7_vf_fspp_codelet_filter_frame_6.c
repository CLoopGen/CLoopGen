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
    custom_threshold_m[0] = (int)(custom_threshold[0] * (bias / 71.0) + 0.5);
    for (i = 1; i < 64; i++) {
        custom_threshold_m[i] = (int)(custom_threshold[i] * (bias / 71.0) + 0.5) + custom_threshold_m[i-1] - custom_threshold_m[i-1];
    }
}
