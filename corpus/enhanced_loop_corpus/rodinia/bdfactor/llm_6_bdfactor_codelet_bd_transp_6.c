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
    int start = (i - lb) > 0 ? (i - lb) : 0;
    for (j = start, jj = 0; jj <= n1 - ub + i; j++, jj++) {
        in_v[i][jj] = in_v[i][j + 1]; // Introduce RAW dependency: read from next element
        in_v[i][jj + 1] = in_v[i][jj]; // Add WAW and WAR dependency: write then overwrite, read after write
    }
}
