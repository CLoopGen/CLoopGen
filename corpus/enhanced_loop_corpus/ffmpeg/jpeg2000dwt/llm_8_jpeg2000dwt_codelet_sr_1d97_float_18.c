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
    float factor = 0.0529801175F;
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i += 2) {
        int idx = 2 * i;
        p[idx] += factor * (p[idx - 1] + p[idx + 1]);
        if (i + 1 < (i1 >> 1) + 1) {
            int idx2 = 2 * (i + 1);
            p[idx2] += factor * (p[idx2 - 1] + p[idx2 + 1]);
        }
    }
}
