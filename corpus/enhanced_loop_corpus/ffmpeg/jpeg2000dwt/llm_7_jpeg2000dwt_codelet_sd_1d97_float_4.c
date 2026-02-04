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
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 1;
    float prev_val = 0.0f;
    for (i = start; i < end; i++) {
        float current = local_p[2 * i] + local_p[2 * i + 2];
        float adjusted = 1.5861339999999999f * (current + prev_val);
        local_p[2 * i + 1] -= adjusted;
        prev_val = current;
    }
}
