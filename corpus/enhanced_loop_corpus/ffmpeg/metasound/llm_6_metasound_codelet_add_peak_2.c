#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern int center;
extern  float *shape_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (j = -width / 2; j < (width + 1) / 2 && shape < shape_end; j++) {
        temp = ppc_gain * *shape++;
        speech[j + center] += temp;
    }
}
