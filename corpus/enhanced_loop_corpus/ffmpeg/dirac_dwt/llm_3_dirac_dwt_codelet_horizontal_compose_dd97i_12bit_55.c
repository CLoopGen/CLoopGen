#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using pointer arithmetic
    // Ensures sequential memory traversal by precomputing base offsets
    int32_t *b_base1 = b + w2 - 1;
    int32_t *b_base2 = b + w2;
    int32_t *tmp_ptr = tmp + 1;
    int32_t *b_ptr = b + 1;
    
    for (x = 1; x < w2; x++) {
        *tmp_ptr = (*b_ptr - (unsigned int)((int)(*(b_base1 + x) + (unsigned int)(*(b_base2 + x)) + 2) >> 2));
        tmp_ptr++;
        b_ptr++;
    }
}
