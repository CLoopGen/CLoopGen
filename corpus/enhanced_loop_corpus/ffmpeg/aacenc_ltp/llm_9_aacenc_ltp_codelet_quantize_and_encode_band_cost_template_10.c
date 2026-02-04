#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern int i;
extern float cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f, sum2 = 0.0f;
    int limit = size - (size % 4);
    for (i = 0; i < limit; i += 4) {
        sum1 += in[i] * in[i] + in[i+1] * in[i+1];
        sum2 += in[i+2] * in[i+2] + in[i+3] * in[i+3];
    }
    for (; i < size; i++) {
        sum1 += in[i] * in[i];
    }
    cost += sum1 + sum2;
}
