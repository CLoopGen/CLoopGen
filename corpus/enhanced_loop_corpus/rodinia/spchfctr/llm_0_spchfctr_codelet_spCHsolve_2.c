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

extern SPMAT *L;
extern int i;
extern int n;
extern int scan_idx;
extern int scan_row;
extern SPROW *row;
extern row_elt *elt;
extern double diag_val;
extern double sum;
extern double *out_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = n - 1; i >= 0; i--) {
        sum = out_ve[i];
        row = &(L->row[i]);
        elt = &(row->elt[row->diag]);
        diag_val = elt->val;
        scan_idx = elt->nxt_idx;
        scan_row = elt->nxt_row;
        
        for (; scan_row >= 0; ) {
            row = &(L->row[scan_row]);
            elt = &(row->elt[scan_idx]);
            sum -= elt->val * out_ve[scan_row];
            scan_idx = elt->nxt_idx;
            scan_row = elt->nxt_row;
        }
        
        out_ve[i] = sum / diag_val;
    }
}
