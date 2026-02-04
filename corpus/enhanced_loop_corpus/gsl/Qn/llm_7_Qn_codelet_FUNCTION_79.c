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
    int local_j = j; // Remove loop-carried dependency on global j by using local accumulator
    for (i = 1; i < ni; ++i) {
        int jj;
        for (jj = left[i]; jj <= right[i]; ++jj) {
            local_j++; // Accumulate in local variable to break RAW/WAW across iterations
        }
    }
    j = local_j; // Update global j once after loop completion
}
