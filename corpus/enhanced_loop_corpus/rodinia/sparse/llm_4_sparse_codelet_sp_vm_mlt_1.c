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

extern SPMAT *A;
extern int i;
extern int j_idx;
extern int m;
extern int max_idx;
extern double tmp;
extern double *x_ve;
extern double *out_ve;
extern SPROW *r;
extern row_elt *elts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m; i++) {
        r = A->row + i;
        max_idx = r->len;
        elts = r->elt;
        tmp = x_ve[i];
        if (max_idx > 0) {
            for (j_idx = 0; j_idx < max_idx; j_idx++, elts++)
                out_ve[elts->col] += elts->val * tmp;
        }
    }
}
