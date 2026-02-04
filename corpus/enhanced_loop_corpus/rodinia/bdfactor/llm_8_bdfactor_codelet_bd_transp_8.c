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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count is halved by stepping by 2, and each iteration performs extra arithmetic (index offset with multiplication)
    int step = 2;
    for (j = n1 - lb + i, jj = n1 - ((ub - i) > (0) ? (ub - i) : (0)); j >= 1; j -= step, jj -= step) {
        in_v[i][jj] = in_v[i][j];
        in_v[i][jj - 1] = in_v[i][j - 1];  // Additional operation per iteration
    }
}
