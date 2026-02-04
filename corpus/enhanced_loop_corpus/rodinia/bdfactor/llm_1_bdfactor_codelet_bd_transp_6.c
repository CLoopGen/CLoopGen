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
    int ii;
    for (ii = i; ii <= i; ii++) {
        for (j = ((ii - lb) > (0) ? (ii - lb) : (0)), jj = 0; jj <= n1 - ub + ii; j++, jj++) {
            in_v[ii][jj] = in_v[ii][j];
        }
    }
}
