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

extern int lim;
extern int len1;
extern int len2;
extern int tmp;
extern row_elt *elts1;
extern row_elt *elts2;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Array (Simulated using pointer arithmetic offset)
    // Use an auxiliary index mapping to access elements in a non-sequential order.
    // Here we simulate indirect access by treating 'nxt_idx' as an offset into a virtual permutation.
    // We follow the nxt_idx chain instead of direct increment.

    row_elt* next1 = elts1;
    row_elt* next2 = elts2;

    for (;;) {
        if ((tmp = next1->col - next2->col) < 0) {
            len1--;
            if (next1->nxt_row == 0 || len1 <= 0 || next1->col >= lim)
                break;
            next1 = &elts1[next1->nxt_idx];  // Indirect jump via nxt_idx
        } else if (tmp > 0) {
            len2--;
            if (next2->nxt_row == 0 || len2 <= 0 || next2->col >= lim)
                break;
            next2 = &elts2[next2->nxt_idx];  // Indirect jump via nxt_idx
        } else {
            sum += next1->val * next2->val;
            len1--;
            len2--;
            if (len1 <= 0 || len2 <= 0 || next1->col >= lim || next2->col >= lim)
                break;
            if (next1->nxt_row != 0 && next2->nxt_row != 0) {
                next1 = &elts1[next1->nxt_idx];
                next2 = &elts2[next2->nxt_idx];
            } else {
                break;
            }
        }
    }

    // Update original pointers if needed for external consistency (not strictly required but realistic)
    elts1 = next1;
    elts2 = next2;
}
