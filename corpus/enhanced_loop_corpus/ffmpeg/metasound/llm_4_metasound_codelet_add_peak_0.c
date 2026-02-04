#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width / 2; i++) {
        if (ppc_gain != 0.0f) {
            speech[i] += ppc_gain * (*shape++);
        }
    }
}
