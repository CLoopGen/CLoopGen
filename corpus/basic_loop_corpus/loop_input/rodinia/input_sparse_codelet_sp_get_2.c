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

int n;
SPMAT *A;
int i;

void init_vars() {
    n = 1 << 20; // ~1M elements, sufficient for ~0.01s on modern CPU

    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    if (!A) exit(1);

    A->m = n;
    A->n = n;
    A->max_m = n;
    A->max_n = n;
    A->flag_col = 0;
    A->flag_diag = 0;

    A->row = (SPROW*)calloc(n, sizeof(SPROW));
    if (!A->row) exit(1);

    A->start_row = (int*)malloc(n * sizeof(int));
    if (!A->start_row) exit(1);

    A->start_idx = (int*)malloc(n * sizeof(int));
    if (!A->start_idx) exit(1);
}

// External symbols defined: n, A, i