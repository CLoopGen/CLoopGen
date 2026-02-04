#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *alphas;
extern unsigned char *indices;
extern unsigned char codes[8];
extern size_t error;
extern size_t _usr_index;
extern size_t j;
extern size_t least;
extern size_t value;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and shuffled access via lookup table
    // Introduce a fixed shuffle order to access alphas and indices indirectly
    const size_t shuffle[16] = {0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15}; // Stride-like indirect access
    ssize_t *alpha_base = alphas;
    unsigned char *index_ptr = indices;

    for (i = 0; i < 16; i++) {
        size_t idx = shuffle[i]; // Indirect indexing
        if (*(alpha_base + idx) == -1) {
            *(index_ptr + idx) = 0;
            continue;
        }
        value = (size_t)*(alpha_base + idx);
        least = (18446744073709551615UL);
        index = 0;
        // Use pointer arithmetic for codes as well
        unsigned char *code_ptr = codes;
        for (j = 0; j < 8; j++) {
            size_t dist = value - (size_t)*(code_ptr + j);
            dist *= dist;
            if (dist < least) {
                least = dist;
                index = j;
            }
        }
        *(index_ptr + idx) = (unsigned char)index;
        error += least;
    }
}
