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
    int idx_current = ni - ii - 1;
    int idx_next = ni - ii - 2;
    double temp = -1. / ((4 * (nn + 1) * (nn + 1) - aa) / qq + ff[idx_next]);
    ff[idx_current] = temp;
    if (ii + 1 < ni) {
        nn = 100 - ii - 2;
        int idx_follow = ni - ii - 3;
        if (idx_follow >= 0) {
            temp = -1. / ((4 * (nn + 1) * (nn + 1) - aa) / qq + ff[idx_follow]);
            ff[idx_next] = temp;
        }
    }
}
}
