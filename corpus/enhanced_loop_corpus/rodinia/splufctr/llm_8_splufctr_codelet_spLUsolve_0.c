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
    // Variant 1: Increased computational intensity with unrolled inner loop (manual unrolling by factor of 2)
    // This reduces loop overhead and increases arithmetic per memory access.
    for (i = 0; i < lim; i++) {
        sum = x_ve[i];
        r = &(A->row[i]);
        len = r->len;
        elt = r->elt;
        idx = 0;
        // Unroll by 2: process two elements per iteration if possible
        while (idx + 1 < len && elt[idx+1].col < i) {
            sum -= elt[idx].val * x_ve[elt[idx].col];
            sum -= elt[idx+1].val * x_ve[elt[idx+1].col];
            idx += 2;
        }
        // Handle remaining element if any
        if (idx < len && elt[idx].col < i) {
            sum -= elt[idx].val * x_ve[elt[idx].col];
        }
        x_ve[i] = sum;
    }
}
