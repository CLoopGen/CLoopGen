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
    float sum[4];
    for (i = 0; i < 4; i++) {
        sum[i] = 0.F;
        for (j = 0; j < 4; j++) {
            sum[i] += vals[j] * wf[8 + i + (j << 2)];
        }
        vals[4 + i] = sum[i] + wf[8 + 16 + i];
    }
}
