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
for (i = 0; i < tab_step && i < order0; i++) {
    double sum1 = 0, sum2 = 0;
    for (j = 0; j < order0; j++) {
        sum1 += src[j] * tab[j * tab_step + i];
        if (i + 1 < tab_step)
            sum2 += src[j] * tab[j * tab_step + i + 1];
    }
    out[i] += sum1;
    if (i + 1 < tab_step)
        out[i + 1] += sum2;
    i++; // Effectively process two output elements per outer loop iteration
}
}
