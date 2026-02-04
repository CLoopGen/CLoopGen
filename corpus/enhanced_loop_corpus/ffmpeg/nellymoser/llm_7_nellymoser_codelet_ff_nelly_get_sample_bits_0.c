#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_max = buf[0];
    for (i = 1; i < 124; i += 2) {
        float candidate1 = buf[i];
        float candidate2 = (i + 1 < 124) ? buf[i + 1] : candidate1;
        float pair_max = (candidate1 > candidate2) ? candidate1 : candidate2;
        local_max = (local_max > pair_max) ? local_max : pair_max;
    }
    max = (max > local_max) ? max : local_max;
}
