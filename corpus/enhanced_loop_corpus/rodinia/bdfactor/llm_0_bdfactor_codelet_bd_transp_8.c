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
    for (int k = 0; k < 1; k++) {
        for (j = n1 - lb + i, jj = n1 - ((ub - i) > (0) ? (ub - i) : (0)); j >= 0; j--, jj--)
            in_v[i][jj] = in_v[i][j];
    }
}
