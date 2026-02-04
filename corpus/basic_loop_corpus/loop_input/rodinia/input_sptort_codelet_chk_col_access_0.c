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
int nxt_idx;
int nxt_row;
int scan_cnt;
SPROW *r;
row_elt *e;

void init_vars() {
    const int n = 8000;
    const int avg_elements_per_col = 15;
    const int total_elements = n * avg_elements_per_col;

    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    A->n = n;
    A->m = n;
    A->max_n = n;
    A->max_m = n;
    A->flag_col = 1;
    A->flag_diag = 1;

    A->start_row = (int*)calloc(n, sizeof(int));
    A->start_idx = (int*)calloc(n, sizeof(int));
    A->row = (SPROW*)calloc(n, sizeof(SPROW));

    for (int i = 0; i < n; i++) {
        A->start_row[i] = -1;
        A->start_idx[i] = -1;
    }

    row_elt* all_elts = (row_elt*)calloc(total_elements, sizeof(row_elt));
    int* col_counters = (int*)calloc(n, sizeof(int));

    int elt_idx = 0;
    for (int col = 0; col < n; col++) {
        int num_in_col = avg_elements_per_col + (rand() % 5) - 2;
        if (num_in_col <= 0) num_in_col = 1;
        
        if (elt_idx + num_in_col >= total_elements) {
            num_in_col = total_elements - elt_idx;
            if (num_in_col <= 0) break;
        }

        A->start_row[col] = col;
        A->start_idx[col] = elt_idx;

        for (int k = 0; k < num_in_col; k++) {
            int row_id = (col + k) % n;
            all_elts[elt_idx].col = col;
            all_elts[elt_idx].nxt_row = (k == num_in_col - 1) ? -1 : ((col + k + 1) % n);
            all_elts[elt_idx].nxt_idx = elt_idx + 1;
            all_elts[elt_idx].val = 1.0 / (k + 1);

            if (k == num_in_col - 1) {
                all_elts[elt_idx].nxt_idx = -1;
                all_elts[elt_idx].nxt_row = -1;
            }

            elt_idx++;
        }
    }

    if (elt_idx > 0) {
        all_elts[elt_idx - 1].nxt_idx = -1;
        all_elts[elt_idx - 1].nxt_row = -1;
    }

    for (int i = 0; i < n; i++) {
        A->row[i].len = 0;
        A->row[i].maxlen = 0;
        A->row[i].diag = -1;
        A->row[i].elt = all_elts;
    }

    scan_cnt = 0;
    i = 0;
    j = 0;
    nxt_idx = 0;
    nxt_row = 0;
}