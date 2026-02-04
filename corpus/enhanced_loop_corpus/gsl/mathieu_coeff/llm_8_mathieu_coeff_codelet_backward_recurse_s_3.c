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
for (ii = 0; ii < ni; ii += 2) {
    if (ii + 1 >= ni) break;
    nn = 100 - ii - 1;
    int idx1 = ni - ii - 1;
    int idx2 = ni - ii - 2;
    double temp1 = ((2 * nn + 1) * (2 * nn + 1) - aa) / qq + ff[ni - ii];
    double temp2 = ((2 * (nn+1) + 1) * (2 * (nn+1) + 1) - aa) / qq + ff[ni - ii - 1];
    ff[idx1] = -1. / temp1;
    ff[idx2] = -1. / temp2;
}
}
