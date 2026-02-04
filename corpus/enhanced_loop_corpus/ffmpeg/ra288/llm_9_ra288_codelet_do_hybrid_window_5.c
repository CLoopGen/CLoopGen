#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *out;
extern float *out2;
extern int i;
extern float buffer1[37];
extern float buffer2[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= order; i++) {
        float temp1 = out2[i] * 0.5625;
        float temp2 = temp1 + buffer1[i];
        float temp3 = temp2 + buffer2[i];
        out2[i] = temp2;
        out[i]  = temp3;
    }
}
