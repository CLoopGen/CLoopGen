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
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = A->m; i < m; i++) {
        A->row[i].len = 0;
        A->row[i].maxlen = 0;
        A->row[i].diag = -1;
        A->row[i].elt = NULL;
    }
}
