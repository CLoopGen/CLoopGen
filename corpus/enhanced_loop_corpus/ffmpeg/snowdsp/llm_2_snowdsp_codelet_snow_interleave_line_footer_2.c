#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int *i;
extern IDWTELEM *low;
extern IDWTELEM *high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    IDWTELEM *low_ptr = low + (*i) + 1;
    IDWTELEM *high_ptr = high + ((*i) >> 1);
    for (; (*i) >= 0; (*i) -= 2, low_ptr -= 2, high_ptr--) {
        *(low_ptr - 0) = *(high_ptr);
        *(low_ptr - 1) = *(high_ptr - ((*i) >> 1)); // Adjusted to maintain logical equivalence using offset from base
    }
}
