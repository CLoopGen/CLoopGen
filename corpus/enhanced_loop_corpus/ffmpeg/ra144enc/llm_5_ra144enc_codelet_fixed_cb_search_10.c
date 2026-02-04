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
    for (i = 0; i < 40; ++i) {
        float temp = gain * work[i];
        if (temp > 1e-6f || temp < -1e-6f) {
            data[i] -= temp;
        }
    }
}
