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
    float gain_sq = best_gain * best_gain;
    for (i = 0; i < 20; i++) {
        float temp = work[i] * gain_sq;
        data[i] -= temp;
        data[i + 20] -= temp * 0.5f;
    }
}
