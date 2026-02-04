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

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

SPMAT *A;
MAT *out;
int i;
int j_idx;
SPROW *row;
row_elt *elt;

void init_vars() {
    const int m = 4000;
    const int n = 3000;
    const int avg_row_len = 64;
    const int total_elts = m * avg_row_len;

    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    out = (MAT*)calloc(1, sizeof(MAT));

    A->m = m;
    A->n = n;
    A->max_m = m;
    A->max_n = n;
    A->flag_col = 0;
    A->flag_diag = 0;
    A->start_row = NULL;
    A->start_idx = NULL;

    A->row = (SPROW*)calloc(m, sizeof(SPROW));

    out->m = m;
    out->n = n;
    out->max_m = m;
    out->max_n = n;
    out->max_size = m * n * sizeof(double);
    out->base = (double*)calloc(m * n, sizeof(double));
    out->me = (double**)calloc(m, sizeof(double*));
    for (int i = 0; i < m; i++) {
        out->me[i] = out->base + i * n;
    }

    row_elt* all_elts = (row_elt*)calloc(total_elts, sizeof(row_elt));
    row_elt* current_elt = all_elts;

    for (int i = 0; i < m; i++) {
        SPROW* r = &(A->row[i]);
        int len = avg_row_len + (rand() % 33) - 16;
        if (len <= 0) len = 1;
        r->len = len;
        r->maxlen = len;
        r->diag = -1;
        r->elt = current_elt;

        for (int j = 0; j < len; j++) {
            current_elt->col = rand() % n;
            current_elt->nxt_row = 0;
            current_elt->nxt_idx = 0;
            current_elt->val = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
            current_elt++;
        }
    }
}