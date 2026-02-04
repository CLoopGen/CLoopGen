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
    // Variant 2: Strided memory access
    // Access every second element in 'shape' and write to non-consecutive locations in 'speech'
    // effectively creating a strided pattern with stride of 2
    int start = -width / 2;
    int idx = start + center;
    int stride = 2;
    for (int j = 0; j < width / stride && (shape + j * stride) < shape_end; j++) {
        speech[idx + j * stride] += ppc_gain * shape[j * stride];
    }
}
