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

extern SPMAT *A;
extern MAT *out;
extern int i;
extern int j_idx;
extern SPROW *row;
extern row_elt *elt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < A->m; i++) {
        row = &(A->row[i]);
        if (row->len == 0) continue;
        elt = &(row->elt[0]);
        int j_end = row->len - (row->len % 4);
        for (j_idx = 0; j_idx < j_end; j_idx += 4, elt += 4) {
            out->me[i][elt[0].col] = elt[0].val;
            out->me[i][elt[1].col] = elt[1].val;
            out->me[i][elt[2].col] = elt[2].val;
            out->me[i][elt[3].col] = elt[3].val;
        }
        for (; j_idx < row->len; j_idx++, elt++)
            out->me[i][elt->col] = elt->val;
    }
}
