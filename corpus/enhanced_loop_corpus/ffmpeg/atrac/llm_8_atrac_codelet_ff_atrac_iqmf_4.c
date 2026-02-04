#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inlo;
extern float *inhi;
extern unsigned int nIn;
extern int i;
extern float *p3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nIn; i += 4) {
        if (i + 1 < nIn) {
            float sum0 = inlo[i] + inhi[i];
            float dif0 = inlo[i] - inhi[i];
            float sum1 = inlo[i + 1] + inhi[i + 1];
            float dif1 = inlo[i + 1] - inhi[i + 1];
            p3[2 * i + 0] = sum0;
            p3[2 * i + 1] = dif0;
            p3[2 * i + 2] = sum1;
            p3[2 * i + 3] = dif1;
        }
        if (i + 2 < nIn) {
            float sum2 = inlo[i + 2] + inhi[i + 2];
            float dif2 = inlo[i + 2] - inhi[i + 2];
            p3[2 * (i + 2) + 0] = sum2;
            p3[2 * (i + 2) + 1] = dif2;
        }
        if (i + 3 < nIn) {
            float sum3 = inlo[i + 3] + inhi[i + 3];
            float dif3 = inlo[i + 3] - inhi[i + 3];
            p3[2 * (i + 3) + 0] = sum3;
            p3[2 * (i + 3) + 1] = dif3;
        }
    }
}
