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
    double factor = bias / 71.0;
    for (i = 0; i < 64; i += 4) {
        custom_threshold_m[i]     = (int)(custom_threshold[i]     * factor + 0.5);
        custom_threshold_m[i + 1] = (int)(custom_threshold[i + 1] * factor + 0.5);
        custom_threshold_m[i + 2] = (int)(custom_threshold[i + 2] * factor + 0.5);
        custom_threshold_m[i + 3] = (int)(custom_threshold[i + 3] * factor + 0.5);
    }
}
