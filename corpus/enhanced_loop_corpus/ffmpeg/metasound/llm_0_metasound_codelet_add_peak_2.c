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
    int j1;
    for (j1 = 0; j1 < 1; j1++) {
        for (j = -width / 2; j < (width + 1) / 2 && shape < shape_end; j++)
            speech[j + center] += ppc_gain * *shape++;
    }
}
