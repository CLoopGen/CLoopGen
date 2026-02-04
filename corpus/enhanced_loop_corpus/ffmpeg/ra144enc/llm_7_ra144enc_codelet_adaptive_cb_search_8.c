#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float best_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_gain = best_gain;
    for (i = 0; i < 40; i += 4) {
        data[i]     -= local_gain * work[i];
        data[i + 1] -= local_gain * work[i + 1];
        data[i + 2] -= local_gain * work[i + 2];
        data[i + 3] -= local_gain * work[i + 3];
    }
}
