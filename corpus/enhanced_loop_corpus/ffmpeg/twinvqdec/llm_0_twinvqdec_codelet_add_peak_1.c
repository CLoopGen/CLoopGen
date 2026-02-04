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
    int j_inner;
    for (j = -width / 2; j < (width + 1) / 2 && shape < shape_end; j++) {
        for (j_inner = 0; j_inner < 1; j_inner++) {
            speech[j + center] += ppc_gain * *shape++;
        }
    }
}
