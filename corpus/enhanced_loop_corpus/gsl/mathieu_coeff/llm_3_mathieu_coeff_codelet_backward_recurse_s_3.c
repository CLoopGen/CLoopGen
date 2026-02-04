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
    int forward_idx = ii;
    int backward_idx = ni - ii - 1;
    ff[backward_idx] = -1. / (((2 * nn + 1) * (2 * nn + 1) - aa) / qq + ff[ni - ii]);
    if (ii + 1 < ni) {
        int next_nn = 100 - (ii + 1) - 1;
        int next_backward_idx = ni - (ii + 1) - 1;
        ff[next_backward_idx] = -1. / (((2 * next_nn + 1) * (2 * next_nn + 1) - aa) / qq + ff[ni - (ii + 1)]);
    }
}
}
