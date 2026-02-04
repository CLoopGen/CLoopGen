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
    double *ve;
} VEC;

extern SPMAT *A;
extern VEC *out;
extern int i;
extern int j_idx;
extern int m;
extern int max_idx;
extern double sum;
extern double *x_ve;
extern SPROW *r;
extern row_elt *elts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m; i++) {
        sum = 0.;
        r = &(A->row[i]);
        max_idx = r->len;
        elts = r->elt;
        if (max_idx <= 0) continue;
        for (j_idx = 0; j_idx < max_idx; j_idx++, elts++)
            sum += elts->val * x_ve[elts->col];
        out->ve[i] = sum;
    }
}
