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
    float temp = ppc_gain * shape[0];
    for (i = 0; i < width / 2; i++) {
        speech[i] += temp;
        temp = ppc_gain * shape[i + 1];
    }
}
