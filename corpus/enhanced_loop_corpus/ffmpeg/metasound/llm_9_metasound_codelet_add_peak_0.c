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
    float gain_squared = ppc_gain * ppc_gain;
    for (i = 0; i < width / 2; i += 2) {
        speech[i] += gain_squared * (*shape++);
        if (i + 1 < width / 2) {
            speech[i + 1] += gain_squared * (*shape++);
        }
    }
}
