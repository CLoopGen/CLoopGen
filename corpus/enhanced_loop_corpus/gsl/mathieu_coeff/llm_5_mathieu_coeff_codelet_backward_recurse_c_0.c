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
    if (nn > 0 && ff[ni - ii] != 0.0) {
        ff[ni - ii - 1] = -1. / ((4 * nn * nn - aa) / qq + ff[ni - ii]);
    } else {
        ff[ni - ii - 1] = 0.0;
    }
}
}
