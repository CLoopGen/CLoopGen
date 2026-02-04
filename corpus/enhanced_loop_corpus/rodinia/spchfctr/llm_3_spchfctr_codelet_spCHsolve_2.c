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

        // Variant 2: Transform linked access into strided array traversal by prefetching elements
        // Simulate vectorizable, consecutive memory access pattern
        double contrib[1000];  // Store contributions in temporary array (consecutive access)
        int count = 0;
        int current = scan_row;
        int idx = scan_idx;

        // Flatten the linked structure into a linear sequence (pre-scan without while)
        for (int step = 0; step < 1000 && current >= 0; step++) {
            row = &(L->row[current]);
            if (idx >= 0 && idx < row->len) {
                elt = &(row->elt[idx]);
                contrib[count++] = elt->val * out_ve[current];
                idx = elt->nxt_idx;
                current = elt->nxt_row;
            } else {
                current = -1; // terminate
            }
        }

        // Accumulate all contributions using direct array access (consecutive read)
        for (int j = 0; j < count; j++) {
            sum -= contrib[j];
        }

        out_ve[i] = sum / diag_val;
    }
}
