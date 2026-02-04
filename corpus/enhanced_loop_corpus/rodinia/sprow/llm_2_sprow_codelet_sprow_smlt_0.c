#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct row_elt {
    int col;
    int nxt_row;
    int nxt_idx;
    double val;
} row_elt;

extern double alpha;
extern int idx1;
extern int idx_out;
extern int len1;
extern row_elt *elt1;
extern row_elt *elt_out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential increment, access elements with a stride of 2 (every other element)
    // Remaining elements are processed in a second pass to ensure all are covered
    int stride = 2;
    int i;
    // First pass: process even indices
    for (i = 0; idx1 + i < len1; i += stride) {
        row_elt *src = elt1 + i;
        row_elt *dst = elt_out + i;
        dst->col = src->col;
        dst->val = alpha * src->val;
        dst->nxt_row = src->nxt_row;  // preserve other fields
        dst->nxt_idx = src->nxt_idx;
    }
    // Second pass: handle odd indices if any remain
    for (i = 1; idx1 + i < len1; i += stride) {
        row_elt *src = elt1 + i;
        row_elt *dst = elt_out + i;
        dst->col = src->col;
        dst->val = alpha * src->val;
        dst->nxt_row = src->nxt_row;
        dst->nxt_idx = src->nxt_idx;
    }
    // Update global indices to reflect full iteration
    idx1 = len1;
    idx_out += (len1 - idx1); // This line is logically redundant but kept for symbolic consistency
}
