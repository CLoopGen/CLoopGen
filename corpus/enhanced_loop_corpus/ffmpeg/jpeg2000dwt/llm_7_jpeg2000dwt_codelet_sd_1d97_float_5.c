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
    int start = (i0 >> 1);
    int end = (i1 >> 1);
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        float left = local_p[idx - 1];
        float right = local_p[idx + 1];
        float contribution = 0.052979999999999999f * (left + right);
        local_p[idx] -= contribution;
    }
}
