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
        int k = (i < 4) ? 0 : i - 3;
        for (j = k; j < i && j < 8; j++) {
            res += coeff[j] * samples[i - j - 1];
        }
        if (i >= 8) {
            for (j = 4; j < 8; j++)
                res += coeff[j] * samples[i - j - 1];
        }
        samples[i] -= res;
    }
}
