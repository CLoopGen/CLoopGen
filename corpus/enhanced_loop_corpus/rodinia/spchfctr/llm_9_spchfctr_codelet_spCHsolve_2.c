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
    // Variant 2: Increased computational intensity by introducing redundant accumulation
    // Trip count remains same, but each iteration performs more arithmetic operations.
    // The inner traversal logic is converted into a counted loop with bounded steps
    // to avoid while, assuming a maximum chain length (e.g., n as upper bound).
    int max_chain = n;  // Conservative upper bound on linked structure length

    for (i = n - 1; i >= 0; i--) {
        sum = out_ve[i];
        row = &(L->row[i]);
        elt = &(row->elt[row->diag]);
        diag_val = elt->val;
        scan_idx = elt->nxt_idx;
        scan_row = elt->nxt_row;

        // Replace original while with bounded for loop to eliminate while
        for (int step = 0; step < max_chain && scan_row >= 0; step++) {
            row = &(L->row[scan_row]);
            elt = &(row->elt[scan_idx]);
            double temp_val = elt->val * out_ve[scan_row];
            sum -= temp_val;  // Original operation

            // Add extra computation to increase computational intensity
            sum += (temp_val * 0.01);  // Artificial inflation (simulates heavier processing)
            sum -= (temp_val * 0.001); // Additional adjustment

            scan_idx = elt->nxt_idx;
            scan_row = elt->nxt_row;
        }
        out_ve[i] = sum / diag_val;
    }
}
