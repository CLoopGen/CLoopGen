#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *restrict v1;
extern float *restrict v2;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float a = v1[i];
        float b = v2[i];
        float diff = a - b;
        float sum = a + b;
        v1[i] = sum;
        v2[i] = diff;
        v1[i] *= 1.0f;
        v2[i] *= 1.0f;
    }
}
