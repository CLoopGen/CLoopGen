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
    int idx = -width / 2;
    for (j = 0; j < width && shape < shape_end; j++, idx++) {
        if (idx + center >= 0) {
            speech[idx + center] += ppc_gain * (*shape);
        }
        shape++;
    }
}
