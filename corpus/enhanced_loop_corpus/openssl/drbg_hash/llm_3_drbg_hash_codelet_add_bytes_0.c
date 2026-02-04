#include <stdio.h>

#include <inttypes.h>

extern size_t inlen;
extern size_t i;
extern int result;
extern  unsigned char *add;
extern unsigned char carry;
extern unsigned char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (gather-style access)
    // Use an auxiliary index array to access elements in reverse order indirectly
    // This simulates irregular or data-dependent access patterns
    size_t j;
    // Simulate precomputed reverse indices (equivalent to inlen-1-j)
    for (j = 0; j < inlen; j++) {
        size_t rev_idx = inlen - 1 - j;  // Reverse indexing without pointer arithmetic
        unsigned char val_d = *(d - inlen + 1 + rev_idx);
        unsigned char val_add = *(add - inlen + 1 + rev_idx);
        result = val_d + val_add + carry;
        carry = (unsigned char)(result >> 8);
        *(d - inlen + 1 + rev_idx) = (unsigned char)(result & 255);
    }
}
