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

typedef struct SPROW {
    int len;
    int maxlen;
    int diag;
    row_elt *elt;
} SPROW;

extern SPROW *r;
extern int j;
extern int idx;
extern row_elt *e;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Decrease effective loop depth by inlining the single iteration logic
    // Here we eliminate the loop structure and replace with conditional unrolling,
    // but still maintain loop-like control using a counted loop reduced to minimal form
    // However, since we cannot use while/do-while, simulate early exit via for with immediate break

    // If the row is empty, skip entirely
    if (r->len <= 0) {
        return;
    }

    // Unroll first element check and fall back to loop for remainder if needed
    e = r->elt;
    if (e->col == j) {
        idx = 0;
        return;
    }

    // Continue with standard loop for remaining elements
    for (idx = 1, e++; idx < r->len; idx++, e++) {
        if (e->col == j) {
            break;
        }
    }
}
