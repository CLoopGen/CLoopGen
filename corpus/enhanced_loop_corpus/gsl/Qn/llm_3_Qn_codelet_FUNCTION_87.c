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
    // Access the left and right arrays using pointers instead of index subscripting
    // to simulate indirect access patterns common in more complex data structures.
    int *left_ptr = left + 1;
    int *right_ptr = right + 1;
    for (i = 1; i < ni; ++i) {
        int jj;
        int l_val = *(left_ptr++);
        int r_val = *(right_ptr++);
        for (jj = l_val; jj <= r_val; ++jj) {
            j++;
        }
    }
}
