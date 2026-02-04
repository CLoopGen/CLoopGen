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
    double sum;
    for (i = 0; i < tab_step; i++) {
        sum = 0;
        for (int k = 0; k < order0; k++) {
            for (j = k; j < k + 1; j++) {
                sum += src[j] * tab[j * tab_step + i];
            }
        }
        out[i] += sum;
    }
}
