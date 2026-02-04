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
    // Variant 2: Indirect memory access via pointer arithmetic
    // Access left and right arrays using base pointers with offset indexing
    // This simulates indirect or displaced access patterns common in kernel optimizations
    int *left_base = left - 1;  // Shift base to use 1-based indexing
    int *right_base = right - 1;
    for (i = 1; i < ni; ++i) {
        int jj;
        int lb = *(left_base + i);   // Indirect access via pointer arithmetic
        int rb = *(right_base + i);
        for (jj = lb; jj <= rb; ++jj) {
            j++;
        }
    }
}
