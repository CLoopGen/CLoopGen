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
    int start = -width / 2;
    int end = (width + 1) / 2;
    float *shape_ptr = shape;
    float *speech_base = speech + center;
    for (j = start; j < end && shape_ptr < shape_end; j++) {
        if (ppc_gain != 0.0f) {
            speech_base[j] += ppc_gain * (*shape_ptr);
        }
        shape_ptr++;
    }
    shape = shape_ptr;
}
