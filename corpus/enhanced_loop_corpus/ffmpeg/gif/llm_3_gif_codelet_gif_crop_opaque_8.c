#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Array
    // Precompute base pointers for each row using an auxiliary array of pointers,
    // then access through these pointers indirectly, simulating indirect addressing.
    // This changes the access pattern to use pointer indirection instead of arithmetic.

    // Since we cannot allocate dynamically without changing function signature,
    // simulate indirect access using precomputed offsets in a stack-allocated array.
    // Only feasible if range isn't too large; here we assume reasonable size.

    const int len = y_end - *y_start + 1;
    uint8_t *buf_ptrs[len];
    uint8_t *ref_ptrs[len];

    for (int i = 0; i < len; i++) {
        int y = *y_start + i;
        buf_ptrs[i] = &buf[y * linesize + *x_start];
        ref_ptrs[i] = &ref[y * ref_linesize + *x_start];
    }

    for (int i = 0; i < len; i++) {
        if (ref_ptrs[i][0] != buf_ptrs[i][0]) {
            same_column = 0;
            break;
        }
    }
}
