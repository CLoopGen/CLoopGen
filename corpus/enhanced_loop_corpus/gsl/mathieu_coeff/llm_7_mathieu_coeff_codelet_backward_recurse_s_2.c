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
    if (ni > 0) {
        ff[ni - 1] = -1.0 / ((4 * (100 - ni + 1) * (100 - ni + 1) - aa) / qq + ff[ni]);
    }
    for (ii = 1; ii < ni; ii++) {
        nn = 100 - ii - 1;
        int prev_idx = ni - ii;
        int curr_idx = ni - ii - 1;
        double computed_denom = (4 * (nn + 1) * (nn + 1) - aa) / qq + ff[prev_idx];
        ff[curr_idx] = -1.0 / computed_denom;
    }
}
