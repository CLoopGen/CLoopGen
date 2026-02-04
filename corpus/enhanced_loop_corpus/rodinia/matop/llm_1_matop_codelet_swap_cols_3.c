#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern double **A_me;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective loop depth by unrolling the loop (assuming small, fixed range)
    // This reduces dynamic iterations by explicitly writing out operations
    if (lo <= hi) {
        k = lo;
        tmp = A_me[i][k];
        A_me[i][k] = A_me[j][k];
        A_me[j][k] = tmp;

        for (k = lo + 1; k <= hi; k++) {
            tmp = A_me[i][k];
            A_me[i][k] = A_me[j][k];
            A_me[j][k] = tmp;
        }
    }
}
