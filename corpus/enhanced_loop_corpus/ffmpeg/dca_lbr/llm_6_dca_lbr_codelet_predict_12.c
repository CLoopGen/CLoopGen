#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern  float *coeff;
extern int nsamples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[8] = {0};
    for (i = 0; i < nsamples; i++) {
        float res = 0;
        for (j = 0; j < 8; j++) {
            int idx = i - j - 1;
            if (idx >= 0)
                temp[j] = coeff[j] * samples[idx];  // Introduce temporary storage to break direct reduction dependency
            res += temp[j];
        }
        samples[i] -= res;
    }
}
