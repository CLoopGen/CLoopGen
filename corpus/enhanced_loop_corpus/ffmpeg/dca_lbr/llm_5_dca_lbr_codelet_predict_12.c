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
    for (i = 0; i < nsamples; i++) {
        float res = 0;
        int valid_start = (i > 0) ? 0 : 8;
        for (j = valid_start; j < 8; j++)
            res += coeff[j] * samples[i - j - 1];
        if (i >= 0)
            samples[i] -= res;
    }
}
