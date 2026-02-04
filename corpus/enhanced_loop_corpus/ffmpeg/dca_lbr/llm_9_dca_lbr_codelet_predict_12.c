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
    for (i = 7; i < nsamples; i += 2) {
        float res1 = 0, res2 = 0;
        for (j = 0; j < 8; j++) {
            res1 += coeff[j] * samples[i - j - 1];
            if (i + 1 < nsamples)
                res2 += coeff[j] * samples[i - j];
        }
        samples[i] -= res1;
        if (i + 1 < nsamples)
            samples[i + 1] -= res2;
    }
}
