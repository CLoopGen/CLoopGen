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
    float local_cost1 = 0.0f;
    float local_cost2 = 0.0f;
    int stride = 2;
    for (i = 0; i < size - 1; i += stride) {
        local_cost1 += in[i] * in[i];
        local_cost2 += in[i + 1] * in[i + 1];
    }
    if (i < size)
        local_cost1 += in[i] * in[i];
    cost += local_cost1 + local_cost2;
}
