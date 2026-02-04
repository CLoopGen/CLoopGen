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
    int forward_idx1 = ii;
    int forward_idx2 = ii + 1;
    int mapped_idx1 = ni - forward_idx1 - 1;
    int mapped_idx2 = ni - forward_idx2 - 1;
    nn = 100 - ii - 1;
    ff[mapped_idx1] = -1. / ((4 * nn * nn - aa) / qq + ff[mapped_idx1 + 1]);
    if (ii + 1 < ni) {
        nn = 100 - (ii + 1) - 1;
        ff[mapped_idx2] = -1. / ((4 * nn * nn - aa) / qq + ff[mapped_idx2 + 1]);
    }
}
}
