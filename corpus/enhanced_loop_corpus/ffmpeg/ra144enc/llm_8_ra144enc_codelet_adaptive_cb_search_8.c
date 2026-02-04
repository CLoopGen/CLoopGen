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
    float local_gain = best_gain * 0.5f;
    for (i = 0; i < 80; i += 2) {
        data[i] -= local_gain * work[i];
        if (i + 1 < 80) {
            data[i + 1] -= local_gain * work[i + 1];
        }
    }
}
