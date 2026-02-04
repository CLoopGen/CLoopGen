#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1 = 0.F, temp2 = 0.F, temp3 = 0.F, temp4 = 0.F;
    for (i = 0; i < size; i += 4) {
        out[i] = temp1;
        out[i + 1] = temp2;
        out[i + 2] = temp3;
        out[i + 3] = temp4;
    }
}
