#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern  float *shape_end;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (j = -width / 2; j < (width + 1) / 2 && shape < shape_end; j += step) {
        float temp = ppc_gain * *shape++;
        speech[j + center] += temp;
        if (shape < shape_end && (j + 1) < (width + 1) / 2) {
            speech[j + 1 + center] += ppc_gain * *shape++;
        }
    }
}
