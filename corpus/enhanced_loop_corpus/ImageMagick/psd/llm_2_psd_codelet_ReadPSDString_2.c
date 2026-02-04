#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (stride of 2)
    // Instead of accessing consecutive memory locations, we now access every second element
    // We assume that p and q are aligned such that striding by 2 remains within bounds
    ptrdiff_t stride = 2;
    char *left = p;
    char *right = q;

    // Adjust right pointer to ensure it's aligned with the stride pattern
    while ((right - left) >= stride) {
        --right;
        if (((right - left) % stride) != 0) continue;
        char *l_ptr = left + (right - left);
        char *r_ptr = right;

        *l_ptr = *l_ptr ^ *r_ptr;
        *r_ptr = *l_ptr ^ *r_ptr;
        *l_ptr = *l_ptr ^ *r_ptr;
    }
}
