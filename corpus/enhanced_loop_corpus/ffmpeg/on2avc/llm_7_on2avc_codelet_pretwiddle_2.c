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
        double sum = out[i];
        for (j = 0; j < order0; j++)
            sum += src[j] * tab[j * tab_step + i];
        out[i] = sum;
    }
}
