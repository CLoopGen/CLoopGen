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
    // Use pointers to traverse left and right arrays indirectly, simulating base+offset access
    // This introduces more complex memory addressing while preserving logic
    int *left_ptr = left + 1;   // Start from left[1]
    int *right_ptr = right + 1; // Start from right[1]
    
    for (i = 1; i < ni; ++i) {
        int jj;
        int l_val = *(left_ptr++);   // Indirect access using pointer dereference and increment
        int r_val = *(right_ptr++);  // Same for right array
        
        for (jj = l_val; jj <= r_val; ++jj) {
            j++;
        }
    }
}
