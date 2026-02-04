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
        int index_current = ni - ii - 1;
        int index_next = ni - ii;
        if (ii == ni - 1) {
            ff[index_current] = -1. / (((2 * nn + 1) * (2 * nn + 1) - aa) / qq + 1.0);
        } else {
            ff[index_current] = -1. / (((2 * nn + 1) * (2 * nn + 1) - aa) / qq + ff[index_next]);
        }
    }
}
