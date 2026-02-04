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
        int idx_prev = ni - ii;
        int idx_curr = ni - ii - 1;
        if (idx_prev < ni) {
            ff[idx_curr] = -1. / ((4 * nn * nn - aa) / qq + ff[idx_prev]);
        } else {
            ff[idx_curr] = -1. / ((4 * nn * nn - aa) / qq + 1.0); // break dependency on uninitialized access
        }
    }
}
