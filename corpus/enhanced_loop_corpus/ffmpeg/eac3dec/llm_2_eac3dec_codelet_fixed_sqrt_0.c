#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;
extern int shift2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride
    int* retval_ptr = &retval;
    int* bit_mask_ptr = &bit_mask;
    int* guess_ptr = &guess;
    int* square_ptr = &square;
    int stride = 1; // Simulated stride for accessing "elements" in a flattened manner

    for (i = 0; i < shift2; i += stride) {
        *(guess_ptr + i) = *(retval_ptr + i) + *(bit_mask_ptr + i);
        accu = (int64_t)(*(guess_ptr + i)) * (*(guess_ptr + i));
        *(square_ptr + i) = (int)((accu + *(bit_mask_ptr + i)) >> bits);
        if (x >= *(square_ptr + i))
            *(retval_ptr + i) += *(bit_mask_ptr + i);
        *(bit_mask_ptr + i) >>= 1;
    }
}
