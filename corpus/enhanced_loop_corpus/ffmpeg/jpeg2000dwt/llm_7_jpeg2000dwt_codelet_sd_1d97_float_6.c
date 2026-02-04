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
    int end = (i1 >> 1);
    if (start < end) {
        local_p[2 * start + 1] += 0.882911 * (local_p[2 * start] + local_p[2 * start + 2]);
        for (i = start + 1; i < end; i++) {
            float prev_contribution = 0.882911 * local_p[2 * i - 2];
            float curr_val = local_p[2 * i] + local_p[2 * i + 2];
            local_p[2 * i + 1] += 0.882911 * curr_val + prev_contribution;
        }
    }
}
