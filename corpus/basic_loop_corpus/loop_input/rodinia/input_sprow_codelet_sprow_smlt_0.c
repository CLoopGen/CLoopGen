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

double alpha;
int idx1;
int idx_out;
int len1;
row_elt *elt1;
row_elt *elt_out;

static row_elt *elt1_buf;
static row_elt *elt_out_buf;

void init_vars() {
    alpha = 2.5;
    len1 = 10000000; // ~160 MB of data (10M elements * 16 bytes per struct approx)

    elt1_buf = (row_elt*)aligned_alloc(64, len1 * sizeof(row_elt));
    elt_out_buf = (row_elt*)aligned_alloc(64, len1 * sizeof(row_elt));

    if (!elt1_buf || !elt_out_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < len1; i++) {
        elt1_buf[i].col = i % 1000;
        elt1_buf[i].nxt_row = (i + 1) % len1;
        elt1_buf[i].nxt_idx = i + 1;
        elt1_buf[i].val = 1.0 + i * 0.001;
    }

    elt1 = elt1_buf;
    elt_out = elt_out_buf;
    idx1 = 0;
    idx_out = 0;
}