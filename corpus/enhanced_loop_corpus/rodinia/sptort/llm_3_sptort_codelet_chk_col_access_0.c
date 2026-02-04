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
    int *base_start_row = A->start_row;
    int *base_start_idx = A->start_idx;
    SPROW *rows = A->row;

    for (j = 0; j < A->n; j++) {
        i = -1;
        nxt_idx = *(base_start_idx + j);
        nxt_row = *(base_start_row + j);

        for (; nxt_row >= 0 && nxt_idx >= 0 && nxt_row > i; ) {
            i = nxt_row;
            r = rows + i;
            e = &(r->elt[nxt_idx]);
            nxt_idx = e->nxt_idx;
            nxt_row = e->nxt_row;
            scan_cnt++;
        }
    }
}
