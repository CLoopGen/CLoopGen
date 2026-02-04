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
    double denom = (base * base - aa) / qq;
    for (int k = 0; k < 3; k++) {
        denom = 1.0 / (denom + ff[ni - ii]);
    }
    ff[ni - ii - 1] = -denom;
}
}
