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
    // Variant 2: Indirect access via index remapping (simulating non-sequential access)
    int indices[32]; // Assuming maximum shift2 is 32 for bounded size
    for (i = 0; i < shift2; i++) {
        indices[i] = i;
    }
    // Simulate shuffled access: reverse order (indirect traversal)
    for (i = 0; i < shift2; i++) {
        int idx = indices[shift2 - 1 - i]; // Reverse mapping
        // Use dummy computation to maintain dependency on idx to prevent optimization
        if (idx >= 0 && idx < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
