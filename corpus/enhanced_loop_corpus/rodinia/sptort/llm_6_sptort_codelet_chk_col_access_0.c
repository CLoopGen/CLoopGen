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
extern int j;
extern int nxt_idx;
extern int nxt_row;
extern int scan_cnt;
extern SPROW *r;
extern row_elt *e;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (j = 0; j < A->n; j++) {
        i = -1;
        nxt_idx = A->start_idx[j];
        nxt_row = A->start_row[j];
        for (; nxt_row >= 0 && nxt_idx >= 0 && nxt_row > i; ) {
            int temp_i = nxt_row;
            SPROW *temp_r = &(A->row[temp_i]);
            row_elt *temp_e = &(temp_r->elt[nxt_idx]);
            nxt_idx = temp_e->nxt_idx;
            nxt_row = temp_e->nxt_row;
            i = temp_i;
            scan_cnt++;
        }
    }
}
