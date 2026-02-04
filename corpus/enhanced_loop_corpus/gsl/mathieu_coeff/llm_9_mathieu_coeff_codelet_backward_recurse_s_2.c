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
    nn = 100 - ii - 1;
    double base = (4 * (nn + 1) * (nn + 1) - aa) / qq;
    double correction = 0.0;
    for (int k = 0; k < 3; k++) {
        correction += ff[ni - ii] * (k + 1);
    }
    ff[ni - ii - 1] = -1. / (base + correction / 6.0);
}
}
