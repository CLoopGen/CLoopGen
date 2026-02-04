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
int m;
int i;

void init_vars() {
    // Set m to a value larger than A->m so the loop runs
    m = 100000;

    // Allocate SPMAT structure
    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    A->m = 50000;  // A->m < m, so loop runs from 50000 to 99999
    A->n = 1000;
    A->max_m = m;
    A->max_n = 1000;
    A->flag_col = 0;
    A->flag_diag = 1;

    // Allocate row array with size max_m to prevent out-of-bounds access
    A->row = (SPROW*)calloc(A->max_m, sizeof(SPROW));

    // Initialize each SPROW in the valid range that might be accessed
    for (int idx = A->m; idx < m; idx++) {
        A->row[idx].len = -1; // Will be set to 0 in loop
        A->row[idx].maxlen = 0;
        A->row[idx].diag = -1;
        A->row[idx].elt = NULL;
    }

    // Allocate start_row and start_idx arrays to satisfy structure assumptions
    A->start_row = (int*)calloc(A->max_m + 1, sizeof(int));
    A->start_idx = (int*)calloc(A->max_m + 1, sizeof(int));
}