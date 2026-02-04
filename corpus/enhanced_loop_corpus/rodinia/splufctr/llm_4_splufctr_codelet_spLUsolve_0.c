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
extern int idx;
extern int len;
extern int lim;
extern double sum;
extern double *x_ve;
extern SPROW *r;
extern row_elt *elt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lim; i++) {
    sum = x_ve[i];
    r = &(A->row[i]);
    len = r->len;
    elt = r->elt;
    for (idx = 0; idx < len; idx++, elt++) {
        if (elt->col >= i) break;
        sum -= elt->val * x_ve[elt->col];
    }
    x_ve[i] = sum;
}
}
