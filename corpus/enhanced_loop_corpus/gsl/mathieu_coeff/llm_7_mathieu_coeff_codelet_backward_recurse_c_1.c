#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double aa;
extern double qq;
extern double *ff;
extern int ni;
extern int ii;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (ii = 0; ii < ni; ii++) {
        nn = 100 - ii - 1;
        int index = ni - ii - 1;
        double base = ((2 * nn + 1) * (2 * nn + 1) - aa) / qq;
        temp_sum += base;
        ff[index] = -1. / (temp_sum + ff[ni - ii]);
        temp_sum = ff[index]; 
    }
}
