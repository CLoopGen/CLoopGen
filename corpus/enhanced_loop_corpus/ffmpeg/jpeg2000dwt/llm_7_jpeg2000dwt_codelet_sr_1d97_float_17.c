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
    for (i = start; i <= end; i++) {
        int idx = 2 * i - 1;
        if (idx >= 0) {
            float right = (2 * i + 1 < (i1 + 1)) ? local_p[2 * i + 1] : 0.0F;
            local_p[idx] -= 0.882911086F * (local_p[2 * i - 2] + local_p[2 * i] + right);
        }
    }
}
