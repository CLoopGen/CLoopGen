#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_gain = gain * 1.5f;
    for (i = 0; i < 20; i++) {
        float temp1 = work[i] * local_gain;
        float temp2 = work[i + 20] * local_gain;
        data[i] -= temp1;
        data[i + 20] -= temp2;
    }
}
