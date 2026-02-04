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
for (i = 0; i < 8; i++) {
    int base = i * 8;
    for (int k = 0; k < 8; k++) {
        int idx = base + k;
        custom_threshold_m[idx] = (int)(custom_threshold[idx] * (bias / 71.) + 0.5);
    }
}
}
