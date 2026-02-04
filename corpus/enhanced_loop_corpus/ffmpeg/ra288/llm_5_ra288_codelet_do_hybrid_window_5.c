#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *out;
extern float *out2;
extern int i;
extern float buffer1[37];
extern float buffer2[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= order; i++) {
        float temp = out2[i] * 0.5625;
        if (temp > -1.0f && temp < 1.0f) {
            out2[i] = temp + buffer1[i];
        } else {
            out2[i] = temp; // Do not add buffer1[i] if temp is outside (-1, 1)
        }
        out[i] = out2[i] + buffer2[i];
    }
}
