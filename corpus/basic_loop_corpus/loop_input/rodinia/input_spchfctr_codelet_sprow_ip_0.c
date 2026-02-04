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

int lim;
int len1;
int len2;
int tmp;
row_elt *elts1;
row_elt *elts2;
double sum;

static row_elt *elts1_buf;
static row_elt *elts2_buf;

void init_vars() {
    // Allocate approximately 64MB total for both arrays to target ~0.01s runtime
    size_t total_size = 1 << 25; // ~32M bytes per array -> ~64MB total
    size_t avg_struct_size = sizeof(row_elt);
    size_t num_elts1 = total_size / (2 * avg_struct_size);
    size_t num_elts2 = total_size / (2 * avg_struct_size);

    elts1_buf = aligned_alloc(64, (num_elts1 + 1) * sizeof(row_elt));
    elts2_buf = aligned_alloc(64, (num_elts2 + 1) * sizeof(row_elt));

    // Initialize control variables
    len1 = num_elts1;
    len2 = num_elts2;
    lim = (int)(num_elts1 * 1.5); // Ensure lim is beyond normal access range
    sum = 0.0;

    // Fill elts1 with increasing column indices
    for (size_t i = 0; i < num_elts1; i++) {
        elts1_buf[i].col = (int)(i * 1.5); // Sparse but increasing
        elts1_buf[i].nxt_row = (int)i + 1;
        elts1_buf[i].nxt_idx = (int)i + 1;
        elts1_buf[i].val = 1.0 + (double)i * 0.01;
    }
    // Sentinel value to prevent out-of-bounds
    elts1_buf[num_elts1].col = lim + 1000;

    // Fill elts2 with overlapping and non-overlapping entries
    for (size_t i = 0; i < num_elts2; i++) {
        elts2_buf[i].col = (int)(i * 1.8); // Slightly different stride
        elts2_buf[i].nxt_row = (int)i + 1;
        elts2_buf[i].nxt_idx = (int)i + 1;
        elts2_buf[i].val = 2.0 + (double)i * 0.02;
    }
    // Sentinel value
    elts2_buf[num_elts2].col = lim + 1000;

    // Set working pointers to start of buffers
    elts1 = elts1_buf;
    elts2 = elts2_buf;
}