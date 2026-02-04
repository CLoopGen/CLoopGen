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
    int start = i0 >> 1;
    int end = i1 >> 1;
    float prev_update = 0.0F;
    for (i = start; i < end; i++) {
        float current_val = local_p[2 * i] + local_p[2 * i + 2];
        float update = 1.58613431F * current_val + prev_update;
        local_p[2 * i + 1] += update;
        prev_update = update * 0.5F;
    }
}
