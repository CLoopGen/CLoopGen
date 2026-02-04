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
extern row_elt *elt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int i = 0; i < A->m; i++) {
        row_elt *elt = A->row[i].elt;
        int len = A->row[i].len;
        int idx = 0;
        for (; idx + 3 < len; idx += 4) {
            elt[idx + 0].val = 0.;
            elt[idx + 1].val = 0.;
            elt[idx + 2].val = 0.;
            elt[idx + 3].val = 0.;
        }
        for (; idx < len; idx++) {
            elt[idx].val = 0.;
        }
    }
}
