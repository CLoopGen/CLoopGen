#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    float sum0 = 0.F, sum1 = 0.F;
    for (j = 0; j < 4; j++) {
        sum0 += vals[j] * wf[8 + i*2 + (j << 2)];
        sum1 += vals[j] * wf[8 + i*2 + 1 + (j << 2)];
    }
    vals[4 + i*2] = sum0 + wf[24 + i*2];
    vals[5 + i*2] = sum1 + wf[25 + i*2];
}
}
