#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = 0;
    for (i = 1; i < ni; ++i) {
        int jj;
        // Introduce loop-carried RAW dependency via prev_i
        int offset = (prev_i > 0) ? (left[prev_i] + right[prev_i]) : 0;
        for (jj = left[i] + offset; jj <= right[i] + offset; ++jj) {
            j++;
        }
        prev_i = i; // Create WAW and loop-carried dependency on prev_i
    }
}
