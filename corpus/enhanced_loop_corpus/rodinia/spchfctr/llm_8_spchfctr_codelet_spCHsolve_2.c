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
    // Variant 1: Computational Complexity Adjustment via Loop Unrolling (factor of 2)
    // This increases arithmetic operations per iteration and reduces loop trip count by unrolling
    // the outer loop to process two iterations at once when possible.
    for (i = n - 1; i >= 1; i -= 2) {
        // Process i-th row
        sum = out_ve[i];
        row = &(L->row[i]);
        elt = &(row->elt[row->diag]);
        diag_val = elt->val;
        scan_idx = elt->nxt_idx;
        scan_row = elt->nxt_row;

        // Simulate while loop using for with single step
        for (; scan_row >= 0; ) {
            row = &(L->row[scan_row]);
            elt = &(row->elt[scan_idx]);
            sum -= elt->val * out_ve[scan_row];
            scan_idx = elt->nxt_idx;
            scan_row = elt->nxt_row;
        }
        out_ve[i] = sum / diag_val;

        // Process (i-1)-th row
        sum = out_ve[i-1];
        row = &(L->row[i-1]);
        elt = &(row->elt[row->diag]);
        diag_val = elt->val;
        scan_idx = elt->nxt_idx;
        scan_row = elt->nxt_row;

        // Simulate while loop using for
        for (; scan_row >= 0; ) {
            row = &(L->row[scan_row]);
            elt = &(row->elt[scan_idx]);
            sum -= elt->val * out_ve[scan_row];
            scan_idx = elt->nxt_idx;
            scan_row = elt->nxt_row;
        }
        out_ve[i-1] = sum / diag_val;
    }

    // Handle remaining element if n is odd
    if (i == 0) {
        sum = out_ve[0];
        row = &(L->row[0]);
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
        out_ve[0] = sum / diag_val;
    }
}
