#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

SPMAT *A;
VEC *out;
int i;
int j_idx;
int m;
int max_idx;
double sum;
double *x_ve;
SPROW *r;
row_elt *elts;

void init_vars() {
    const int data_size_mb = 64;
    const int avg_row_elements = 100;
    m = (data_size_mb * 1024 * 1024) / (avg_row_elements * sizeof(row_elt));
    if (m < 1) m = 1;

    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    out = (VEC*)calloc(1, sizeof(VEC));
    x_ve = (double*)calloc(m, sizeof(double));

    A->m = m;
    A->n = m;
    A->max_m = m;
    A->max_n = m;
    A->flag_col = 0;
    A->flag_diag = 1;
    A->start_row = NULL;
    A->start_idx = NULL;

    A->row = (SPROW*)calloc(m, sizeof(SPROW));
    out->dim = m;
    out->max_dim = m;
    out->ve = (double*)calloc(m, sizeof(double));

    for (int i = 0; i < m; i++) {
        int len = 1 + (rand() % (2 * avg_row_elements - 1));
        A->row[i].len = len;
        A->row[i].maxlen = len;
        A->row[i].diag = i;
        A->row[i].elt = (row_elt*)malloc(len * sizeof(row_elt));
        for (int j = 0; j < len; j++) {
            A->row[i].elt[j].col = rand() % m;
            A->row[i].elt[j].nxt_row = (i + 1) % m;
            A->row[i].elt[j].nxt_idx = j;
            A->row[i].elt[j].val = 1.0 + (rand() % 1000) / 1000.0;
        }
        x_ve[i] = 1.0 + (rand() % 1000) / 1000.0;
        out->ve[i] = 0.0;
    }

    i = 0;
    j_idx = 0;
    max_idx = 0;
    sum = 0.0;
    r = NULL;
    elts = NULL;
}