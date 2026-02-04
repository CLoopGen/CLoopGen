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
    float local_gain = ppc_gain * 1.5f;
    for (j = -width / 2; j < (width + 3) / 2 && shape + 1 < shape_end; j++) {
        float val1 = *shape++;
        float val2 = *shape++;
        speech[j + center] += local_gain * val1;
        if (j + center + 1 < width) {
            speech[j + center + 1] += local_gain * val2;
        }
    }
}
