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
extern int j_idx;
extern int len;
extern int m;
extern SPROW *row;
extern row_elt *r_elt;
extern int *start_row;
extern int *start_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = m - 1; i >= 0; i--) {
        row = &(A->row[i]);
        len = row->len;
        // Use strided access by precomputing base pointer and using index arithmetic
        for (j_idx = 0; j_idx < len; j_idx++) {
            r_elt = &row->elt[j_idx]; // Strided access via indexing instead of pointer increment
            j = r_elt->col;
            r_elt->nxt_row = start_row[j];
            r_elt->nxt_idx = start_idx[j];
            start_row[j] = i;
            start_idx[j] = j_idx;
        }
    }
}
