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
    float temp;
    for (i = 0; i <= order; i++) {
        temp = out2[i] * 0.5625 + buffer1[i];
        out[i] = temp + buffer2[i];
        out2[i] = temp;
    }
}
