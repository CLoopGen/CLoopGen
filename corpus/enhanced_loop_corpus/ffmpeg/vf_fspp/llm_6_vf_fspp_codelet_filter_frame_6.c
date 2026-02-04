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
    int temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = (int)(custom_threshold[i] * (bias / 71.0) + 0.5);
    }
    for (i = 0; i < 64; i++) {
        custom_threshold_m[i] = temp[i];
    }
}
