#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

SPMAT *L;
int i;
int n = 8000;
int scan_idx;
int scan_row;
SPROW *row;
row_elt *elt;
double diag_val;
double sum;
double *out_ve;

void init_vars() {
    const int data_size = 8000;
    n = data_size;
    L = (SPMAT*)calloc(1, sizeof(SPMAT));
    L->m = data_size;
    L->n = data_size;
    L->max_m = data_size;
    L->max_n = data_size;
    L->flag_col = 0;
    L->flag_diag = 1;
    L->row = (SPROW*)calloc(data_size, sizeof(SPROW));
    L->start_row = (int*)calloc(data_size, sizeof(int));
    L->start_idx = (int*)calloc(data_size, sizeof(int));
    out_ve = (double*)calloc(data_size, sizeof(double));

    srand(42);
    for (int idx = 0; idx < data_size; idx++) {
        out_ve[idx] = (double)(rand() % 1000) / 10.0;
        SPROW* r = &(L->row[idx]);
        r->len = 1 + (idx % 5);
        r->maxlen = r->len;
        r->diag = 0;
        r->elt = (row_elt*)calloc(r->maxlen, sizeof(row_elt));
        for (int j = 0; j < r->len; j++) {
            r->elt[j].col = (idx + j) % data_size;
            r->elt[j].val = (double)(rand() % 1000) / 100.0 + 1.0;
            if (j == 0) {
                r->diag = j;
                r->elt[j].nxt_idx = j;
                r->elt[j].nxt_row = -1;
            } else {
                r->elt[j].nxt_idx = (j - 1 + r->len) % r->maxlen;
                r->elt[j].nxt_row = (idx - (j % 3)) >= 0 ? (idx - (j % 3)) : -1;
            }
        }
        L->start_row[idx] = idx % 2 ? idx : -1;
        L->start_idx[idx] = idx % 2 ? (idx % r->maxlen) : 0;
    }

    for (int i = data_size - 1; i >= 0; i--) {
        SPROW* r = &(L->row[i]);
        if (r->len > 0) {
            r->elt[r->diag].nxt_row = -1;
            for (int j = 1; j < r->len; j++) {
                int next_row = i - (j * 7 % 50);
                r->elt[j].nxt_row = next_row > 0 ? next_row : -1;
                r->elt[j].nxt_idx = (j - 1) % r->maxlen;
            }
        }
    }
}