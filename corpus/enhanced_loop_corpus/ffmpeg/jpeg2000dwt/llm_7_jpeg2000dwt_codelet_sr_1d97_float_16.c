#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_p = p;
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 2;
    float accumulator = 0.0F;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        float neighbor_sum = local_p[idx - 1] + local_p[idx + 1];
        accumulator += 0.443506867F * neighbor_sum;
        local_p[idx] -= accumulator;
    }
}
