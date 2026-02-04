#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_simple_mmx_perm[64];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward write with reverse read and indirect indexing
    // Alters access pattern by reading src in reverse order but still using the permutation for dst placement
    for (i = 0; i < 64; i++) {
        int reversed_index = 63 - i;  // Reverse traversal of src
        dst[idct_simple_mmx_perm[i]] = src[reversed_index];
    }
}
