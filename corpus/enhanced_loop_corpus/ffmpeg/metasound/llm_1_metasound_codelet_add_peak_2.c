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
    int outer_j;
    int step = 1;
    for (outer_j = -width / 2; outer_j < (width + 1) / 2; outer_j += step) {
        j = outer_j;
        if (!(shape < shape_end)) break;
        speech[j + center] += ppc_gain * *shape++;
    }
}
