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
    int start = (i - lb) > 0 ? (i - lb) : 0;
    int step = 2; // Process every second element to reduce trip count
    for (j = start, jj = 0; jj <= n1 - ub + i; j += step, jj++) {
        double temp = in_v[i][j] * 1.5 + 0.5; // Additional arithmetic: scale and offset
        in_v[i][jj] = temp;
        if (jj + 1 <= n1 - ub + i) {
            in_v[i][jj + 1] = in_v[i][j]; // Extra write operation to increase memory activity
        }
    }
}
