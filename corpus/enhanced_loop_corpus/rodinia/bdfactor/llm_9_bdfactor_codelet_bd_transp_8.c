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
    // Variant 2: Reduced computational intensity with simplified bounds and single arithmetic expression
    // Eliminate conditional ternary in loop initialization by pre-computing effective upper bound
    // Also reduce index complexity by removing redundant calculations in update
    int ub_index = (ub - i > 0) ? ub - i : 0;
    for (j = n1 - lb + i, jj = n1 - ub_index; j >= 0 && jj >= 0; j--, jj--) {
        in_v[i][jj] = in_v[i][j];
    }
}
