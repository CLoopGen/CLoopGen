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
    int outer_j;
    int step = (width + 1) / 2 - (-width / 2);
    int iter;
    for (iter = 0; iter < step; iter++) {
        outer_j = -width / 2 + iter;
        if (shape >= shape_end) break;
        speech[outer_j + center] += ppc_gain * *shape++;
    }
}
