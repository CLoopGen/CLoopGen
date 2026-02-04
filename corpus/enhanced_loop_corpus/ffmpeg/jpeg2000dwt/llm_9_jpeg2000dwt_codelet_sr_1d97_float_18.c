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
    const float f1 = 0.0529801175F;
    const float f2 = 0.105960235F; // 2 * f1
    for (i = (i0 >> 1) + 1; i < (i1 >> 1); i++) {
        int idx = 2 * i;
        float temp1 = p[idx - 1] + p[idx + 1];
        float temp2 = p[idx - 2] + p[idx] + p[idx] + p[idx + 2]; // extended stencil
        p[idx] += f1 * temp1 + f2 * (p[idx - 2] + p[idx + 2]) * 0.25F;
    }
}
