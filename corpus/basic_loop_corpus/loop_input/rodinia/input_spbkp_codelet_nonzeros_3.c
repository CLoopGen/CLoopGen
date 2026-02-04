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
int cnt;
int i;

void init_vars() {
    const int num_rows = 1000000;  // ~8-16 MB of data, sufficient for ~0.01 sec runtime

    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    A->m = num_rows;
    A->n = num_rows;
    A->max_m = num_rows;
    A->max_n = num_rows;
    A->flag_col = 0;
    A->flag_diag = 1;

    A->row = (SPROW*)calloc(num_rows, sizeof(SPROW));
    A->start_row = (int*)calloc(num_rows, sizeof(int));
    A->start_idx = (int*)calloc(num_rows, sizeof(int));

    for (int idx = 0; idx < num_rows; idx++) {
        A->row[idx].len = idx % 37;  // Vary length between 0 and 36
        A->row[idx].maxlen = idx % 37;
        A->row[idx].diag = idx % (idx % 37 + 1);  // Ensure within bounds
        if (A->row[idx].len > 0) {
            A->row[idx].elt = (row_elt*)calloc(A->row[idx].len, sizeof(row_elt));
            for (int j = 0; j < A->row[idx].len; j++) {
                A->row[idx].elt[j].col = j % num_rows;
                A->row[idx].elt[j].nxt_row = (idx + 1) % num_rows;
                A->row[idx].elt[j].nxt_idx = (j + 1) % A->row[idx].len;
                A->row[idx].elt[j].val = 1.0 / (j + 1);
            }
        } else {
            A->row[idx].elt = NULL;
        }
        A->start_row[idx] = idx;
        A->start_idx[idx] = 0;
    }

    cnt = 0;
    i = 0;
}