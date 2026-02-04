#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern float32 **data;
extern int32 n_vec;
extern int32 n_dim;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Arithmetic
    // Use explicit pointer arithmetic to access `data` and `mean`, simulating indirect or computed addressing.
    // This changes the access pattern to use dereferenced pointers with offsets instead of array indexing.
    float32 *m_ptr = mean;
    for (i = 0; i < n_vec; i++) {
        float32 **d_row = &data[i];  // Indirect row pointer
        for (j = 0; j < n_dim; j++) {
            // Use pointer arithmetic for both mean and data access
            *(m_ptr + j) += (*(*d_row + j));
        }
    }
}
