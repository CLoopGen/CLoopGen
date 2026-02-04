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
    nn = 100 - ii - 1;
    int index = ni - ii - 1;
    ff[index] = -1. / (((2 * nn + 1) * (2 * nn + 1) - aa) / qq + ff[ni - ii]);
}
}
