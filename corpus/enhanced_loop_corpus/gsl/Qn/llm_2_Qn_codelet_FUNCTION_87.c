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
    // Instead of accessing left[i] and right[i] consecutively, we introduce a stride of 2
    // and handle edge cases by looping only over even indices.
    for (i = 2; i < ni; i += 2) {
        int jj;
        int l_val = left[i];
        int r_val = right[i];
        for (jj = l_val; jj <= r_val; ++jj) {
            j++;
        }
    }
}
