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
    // Variant 1: Strided memory access pattern
    // Instead of accessing left[i] and right[i] consecutively, access them with a fixed stride (e.g., every 2nd element)
    // We simulate strided behavior by stepping through i with stride 2, adjusting loop bounds accordingly.
    for (i = 1; i < ni; i += 2) {
        int jj;
        int left_val = (i < ni) ? left[i] : 0;
        int right_val = (i < ni) ? right[i] : -1;
        for (jj = left_val; jj <= right_val; ++jj) {
            j++;
        }
    }
}
