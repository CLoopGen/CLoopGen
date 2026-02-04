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
for (ii = 0; ii < ni; ii++) {
    for (int k = 0; k < 1; k++) {
        nn = 100 - ii - 1;
        ff[ni - ii - 1] = -1. / ((4 * nn * nn - aa) / qq + ff[ni - ii]);
    }
}
}
