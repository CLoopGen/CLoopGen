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

int i;
SPMAT *A;

void init_vars() {
    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    if (!A) exit(1);

    A->m = 8000;
    A->n = 8000;
    A->max_m = A->m;
    A->max_n = A->n;
    A->flag_col = 0;
    A->flag_diag = 0;

    A->start_row = (int*)calloc(A->n, sizeof(int));
    if (!A->start_row) exit(1);

    A->start_idx = (int*)calloc(A->n, sizeof(int));
    if (!A->start_idx) exit(1);

    A->row = (SPROW*)calloc(A->m, sizeof(SPROW));
    if (!A->row) exit(1);
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}