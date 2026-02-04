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
    for (i = 0; i < 64; ++i) {
        int temp_val = custom_threshold[i];
        if (temp_val == 0) continue;
        custom_threshold_m[i] = (int)(temp_val * (bias / 71.) + 0.5);
    }
}
