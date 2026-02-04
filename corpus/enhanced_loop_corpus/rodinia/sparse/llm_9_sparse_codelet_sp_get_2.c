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

extern int n;
extern SPMAT *A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n; i++) {
        A->start_row[i] = -1;
        A->start_idx[i] = -1;
        for (j = 0; j < 2 && A->row[i].elt != NULL && j < A->row[i].len; j++) {
            A->row[i].elt[j].val *= 2.0;
        }
    }
}
