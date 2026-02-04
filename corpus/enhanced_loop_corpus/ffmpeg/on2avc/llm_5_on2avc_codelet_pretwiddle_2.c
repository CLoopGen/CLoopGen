#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int tab_step;
extern int order0;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < tab_step; i++) {
        double sum = 0;
        for (j = 0; j < order0; j++) {
            if (src[j] != 0.0f)
                sum += src[j] * tab[j * tab_step + i];
        }
        if (sum > 0.001 || sum < -0.001)
            out[i] += sum;
    }
}
