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
    int trip_count = width;
    for (j = 0; j < trip_count && (shape + j) < shape_end; j++) {
        int idx = j - width / 2 + center;
        float gain_val = ppc_gain * shape[j];
        speech[idx] += gain_val;
        speech[idx] += gain_val * 0.1f;  // Extra arithmetic to increase computational intensity
    }
}
