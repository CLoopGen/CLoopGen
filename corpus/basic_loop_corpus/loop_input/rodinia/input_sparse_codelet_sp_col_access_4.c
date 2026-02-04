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

typedef struct SPMAT {
    int m;
    int n;
    int max_m;
    int max_n;
    char flag_col;
    char flag_diag;
    SPROW *row;
    int *start_row;
    int *start_idx;
} SPMAT;

SPMAT *A;
int i;
int j;
int j_idx;
int len;
int m;
SPROW *row;
row_elt *r_elt;
int *start_row;
int *start_idx;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime: aim for moderate memory footprint
    // Each outer loop iteration processes row[i].len elements.
    // Let's use m = 4000, average row length ~200 -> total ~800k elements, reasonable for 0.01s
    m = 4000;
    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    A->m = m;
    A->n = 4000;
    A->max_m = m;
    A->max_n = 4000;
    A->flag_col = 0;
    A->flag_diag = 0;

    // Allocate rows
    A->row = (SPROW*)calloc(m, sizeof(SPROW));
    
    // Total non-zero count estimate
    size_t total_nnz = 0;
    for (int idx = 0; idx < m; idx++) {
        // Decreasing length with row index to simulate realistic sparse pattern
        int row_len = (m - idx) * 200 / m + 50;  // between 50 and 250
        A->row[idx].len = row_len;
        A->row[idx].maxlen = row_len;
        A->row[idx].diag = -1;

        // Allocate row elements
        A->row[idx].elt = (row_elt*)calloc(row_len, sizeof(row_elt));
        
        // Initialize each element in the row
        for (int jdx = 0; jdx < row_len; jdx++) {
            // Spread column indices across [0, n)
            A->row[idx].elt[jdx].col = (idx * 73471 + jdx * 101) % A->n;
            A->row[idx].elt[jdx].nxt_row = -1;
            A->row[idx].elt[jdx].nxt_idx = -1;
            A->row[idx].elt[jdx].val = (double)(idx + jdx) / 100.0;
        }
        total_nnz += row_len;
    }

    // Allocate and initialize start_row and start_idx arrays based on A->n
    A->start_row = (int*)calloc(A->n, sizeof(int));
    A->start_idx = (int*)calloc(A->n, sizeof(int));

    // Initialize start arrays to -1 to indicate no previous entry
    for (int k = 0; k < A->n; k++) {
        A->start_row[k] = -1;
        A->start_idx[k] = -1;
    }

    // Assign global pointers
    start_row = A->start_row;
    start_idx = A->start_idx;
}