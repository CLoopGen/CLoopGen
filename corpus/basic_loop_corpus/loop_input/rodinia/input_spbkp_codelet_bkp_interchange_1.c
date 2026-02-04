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
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

SPMAT *A;
int tmp_idx;
IVEC *done_list;

void init_vars() {
    A = (SPMAT *)calloc(1, sizeof(SPMAT));
    done_list = (IVEC *)calloc(1, sizeof(IVEC));

    A->n = 1000000; // ~4MB of data for done_list initialization loop
    A->m = 1000;
    A->max_m = 1000;
    A->max_n = 1000000;
    A->flag_col = 0;
    A->flag_diag = 0;
    A->row = NULL;
    A->start_row = NULL;
    A->start_idx = NULL;

    done_list->dim = A->n;
    done_list->max_dim = A->n;
    done_list->ive = (int *)calloc(A->n, sizeof(int));
}