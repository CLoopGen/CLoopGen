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
for (ii = 0; ii < ni && ii < 50; ii++) {
    nn = 50 - ii - 1;
    double base = (2.0 * nn + 1.0);
    double term = base * base;
    double denom = (term - aa) / qq;
    for (int k = 0; k < 3; k++) {
        denom += (ff[ni - ii] + k) * 0.01;
    }
    ff[ni - ii - 1] = -1.0 / denom;
}
}
