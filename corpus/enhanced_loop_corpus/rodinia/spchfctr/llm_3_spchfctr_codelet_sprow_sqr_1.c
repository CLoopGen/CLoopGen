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
extern row_elt *elts;
extern int idx;
extern int len;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Array (simulated using pointer arithmetic)
    // Assume we have an auxiliary index array that defines access order
    // Since we cannot modify global declarations, simulate indirect pattern with alternating indices
    sum = 0.0;
    for (idx = 0; idx < len; idx++) {
        // Simulate indirect access: access elements in shuffled order (e.g., from both ends)
        int alt_idx = (idx % 2 == 0) ? idx/2 : len - 1 - idx/2;
        row_elt *current = &elts[alt_idx];
        if (current->col >= lim)
            break;
        tmp = current->val;
        sum += tmp * tmp;
    }
}
