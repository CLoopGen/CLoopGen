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
    // Variant 2: Indirect Array Access via Pointer Arithmetic
    // Use pointer arithmetic to access left and right arrays indirectly
    // This simulates indirect memory access patterns common in sparse computations
    int *left_ptr = left + 1;  // Start from left[1]
    int *right_ptr = right + 1; // Start from right[1]
    for (i = 1; i < ni; ++i) {
        int jj;
        for (jj = *left_ptr; jj <= *right_ptr; ++jj) {
            j++;
        }
        left_ptr++;   // Move to next element via pointer
        right_ptr++;  // Move to next element via pointer
    }
}
