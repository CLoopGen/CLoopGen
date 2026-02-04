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
int k;
for (i = 0; i < tab_step; i++) {
    double sum = 0;
    for (j = 0; j < order0; j += 2) {
        if (j + 1 < order0)
            sum += src[j] * tab[j * tab_step + i] + src[j+1] * tab[(j+1) * tab_step + i];
        else
            sum += src[j] * tab[j * tab_step + i];
    }
    out[i] += sum;
}
}
