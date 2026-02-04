#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tab_step;
extern int order1;
extern float *src2;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum;
    for (i = 0; i < tab_step; i++) {
        sum = 0;
        for (int k = 0; k < order1; k++) {
            for (j = k; j < k + 1; j++) {
                sum += src2[j] * tab[j * tab_step + i];
            }
        }
        out[i] += sum;
    }
}
