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
        j = 2 * i;
        speech[j] += ppc_gain * shape[0];
        speech[j + 1] += ppc_gain * shape[1];
        shape += 2;
    }
}
