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
    float sum;
    for (i = 0; i < 4; i++) {
        sum = 0.F;
        for (int k = 0; k < 4; ++k) {
            for (j = k; j < k + 1; j++) {
                sum += vals[j] * wf[8 + i + (j << 2)];
            }
        }
        vals[4 + i] = sum + wf[8 + 16 + i];
    }
}
