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
    // Variant 1: Introduce a WAW (Write-After-Write) dependency by splitting the write into two steps
    // and adding a temporary variable to create intra-loop dependency.
    double temp;
    for (j = n1 - lb + i, jj = n1 - ((ub - i) > (0) ? (ub - i) : (0)); j >= 0; j--, jj--) {
        temp = in_v[i][j];
        in_v[i][jj] = temp;
        in_v[i][jj] += 0.0; // Artificial WAW: redundant write to same location
    }
}
