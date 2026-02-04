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
    double temp[tab_step];
    for (i = 0; i < tab_step; i++) {
        temp[i] = 0;
        for (j = 0; j < order1; j++)
            temp[i] += src2[j] * tab[j * tab_step + i];
    }
    for (i = 0; i < tab_step; i++) {
        out[i] += temp[i];
    }
}
