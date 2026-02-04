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
    for (i = 0; i < tab_step; i++) {
        double sum = out[i]; // Introduce WAW dependency by reading out[i] before write
        for (j = 0; j < order1; j++)
            sum += src2[j] * tab[j * tab_step + i];
        out[i] = sum; // Convert += to direct assignment, creating a different WAW pattern
    }
}
