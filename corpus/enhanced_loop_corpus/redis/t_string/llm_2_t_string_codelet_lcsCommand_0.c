#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds a;
extern sds b;
extern uint32_t alen;
extern uint32_t blen;
extern uint32_t *lcs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Row-major Traversal with Pointer Arithmetic
    uint32_t *lcs_ptr = lcs;
    for (uint32_t i = 0; i <= alen; i++) {
        for (uint32_t j = 0; j <= blen; j++) {
            if (i == 0 || j == 0) {
                *lcs_ptr = 0;
            } else if (a[i - 1] == b[j - 1]) {
                *lcs_ptr = *(lcs_ptr - (blen + 1) - 1) + 1;
            } else {
                uint32_t lcs1 = *(lcs_ptr - (blen + 1));  // top
                uint32_t lcs2 = *(lcs_ptr - 1);           // left
                *lcs_ptr = lcs1 > lcs2 ? lcs1 : lcs2;
            }
            lcs_ptr++;
        }
    }
}
