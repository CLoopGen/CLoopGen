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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing left[i] and right[i] consecutively, access them with a stride of 2
    // This changes the memory access pattern to non-unit stride, potentially affecting cache behavior
    for (i = 1; i < ni; i += 2) {
        int jj;
        if (i < ni) { // Ensure index is valid after striding
            for (jj = left[i]; jj <= right[i]; ++jj) {
                j++;
            }
        }
    }
}
