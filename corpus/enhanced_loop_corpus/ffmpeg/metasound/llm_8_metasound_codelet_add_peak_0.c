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
    int j;
    for (i = 0; i < width / 4; i++) {
        speech[i] += ppc_gain * (*shape++);
        speech[i + width/4] += ppc_gain * (*shape++);
    }
}
