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
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern SPMAT *A;
extern int tmp_idx;
extern IVEC *done_list;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < A->n; i += 2) {
        if (i < A->n) {
            done_list->ive[i] = 0;
        }
        if (i + 1 < A->n) {
            done_list->ive[i + 1] = 0;
        }
    }
}
