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

extern SPMAT *B;
extern SPROW *r;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < B->m; i += 2) {
        r = &(B->row[i]);
        for (j = 0; j < r->len; j++) {
            if (r->elt[j].val == 0.0) 
                break;
        }
        if (i + 1 < B->m) {
            r = &(B->row[i+1]);
            for (j = 0; j < r->len; j++) {
                if (r->elt[j].val == 0.0) 
                    break;
            }
        }
    }
}
