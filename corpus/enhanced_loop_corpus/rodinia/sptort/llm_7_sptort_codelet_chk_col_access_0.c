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
    int local_scan_cnt = 0;
    for (j = 0; j < A->n; j++) {
        i = -1;
        nxt_idx = A->start_idx[j];
        nxt_row = A->start_row[j];
        int current_row = nxt_row;
        int current_idx = nxt_idx;
        for (; current_row >= 0 && current_idx >= 0 && current_row > i; ) {
            i = current_row;
            r = &(A->row[i]);
            e = &(r->elt[current_idx]);
            current_idx = e->nxt_idx;
            current_row = e->nxt_row;
            local_scan_cnt++;
        }
    }
    scan_cnt += local_scan_cnt;
}
