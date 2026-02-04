#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int lb;
extern int ub;
extern int n1;
extern double **in_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = ((i - lb) > (0) ? (i - lb) : (0)), jj = 0; jj <= n1 - ub + i; j++, jj++) {
        if (j >= 0 && jj < n1) {
            in_v[i][jj] = in_v[i][j];
        }
    }
}
