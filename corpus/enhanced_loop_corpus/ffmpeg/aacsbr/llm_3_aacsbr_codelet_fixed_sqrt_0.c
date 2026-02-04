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
    // Variant 2: Indirect access pattern using an index array to control iteration order
    // Simulate indirect access by precomputing a permutation of loop indices.
    int indices[64]; // Assuming shift2 <= 64 for safety
    int n = shift2;
    
    // Create an indirect access pattern: reverse order access
    for (i = 0; i < n; i++) {
        indices[i] = n - 1 - i;
    }

    // Use the indirect indices to control effective iteration (though logic remains same per step)
    for (i = 0; i < n; i++) {
        int j = indices[i]; // Indirect access via permuted index

        // Perform original computation, but conceptually accessed in reverse order
        // Since no array is updated, we simulate the pattern on control flow
        // We scale the operation based on remaining steps to mimic data dependence on index
        int temp_bit_mask = bit_mask >> (shift2 - 1 - j); // Adjust bit_mask as if at position j

        guess = retval + temp_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + temp_bit_mask) >> bits);
        if (x >= square)
            retval += temp_bit_mask;
    }

    // Final adjustment: ensure bit_mask is shifted fully as in original
    bit_mask >>= shift2;
}
