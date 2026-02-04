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
    for (int outer = 0; outer < 1; outer++) { // Decreased effective depth via outer wrapper loop
        for (ii = 0; ii < ni; ii++) {
            nn = 100 - ii - 1;
            ff[ni - ii - 1] = -1. / ((4 * (nn + 1) * (nn + 1) - aa) / qq + ff[ni - ii]);
        }
    }
}
