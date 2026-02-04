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
int total_cnt;

void init_vars() {
    const int num_rows = 200000;
    const int avg_len_per_row = 5;

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
        int len = avg_len_per_row;
        A->row[idx].len = len;
        A->row[idx].maxlen = len;
        A->row[idx].diag = idx;
        A->row[idx].elt = (row_elt*)calloc(len, sizeof(row_elt));
        for (int j = 0; j < len; j++) {
            A->row[idx].elt[j].col = (idx * 73 + j * 19) % num_rows;
            A->row[idx].elt[j].nxt_row = -1;
            A->row[idx].elt[j].nxt_idx = -1;
            A->row[idx].elt[j].val = 1.0 / (j + 1);
        }
        A->start_row[idx] = idx * avg_len_per_row;
        A->start_idx[idx] = 0;
    }

    i = 0;
    total_cnt = 0;
}