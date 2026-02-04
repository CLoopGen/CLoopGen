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

SPMAT *B;
SPROW *r;
int i;
int j;

static row_elt **all_elts;
static int total_elements;

void init_vars() {
    // Target data size ~64MB to ensure loop runs ~0.01s on modern CPU
    const int total_rows = 8000;
    const int avg_elements_per_row = 20;
    const int total_data_size = total_rows * avg_elements_per_row;

    B = (SPMAT*)calloc(1, sizeof(SPMAT));
    B->m = total_rows;
    B->n = total_rows;
    B->max_m = total_rows;
    B->max_n = total_rows;
    B->flag_col = 0;
    B->flag_diag = 1;

    B->row = (SPROW*)calloc(total_rows, sizeof(SPROW));
    B->start_row = (int*)calloc(total_rows, sizeof(int));
    B->start_idx = (int*)calloc(total_rows, sizeof(int));

    all_elts = (row_elt**)calloc(total_rows, sizeof(row_elt*));
    total_elements = 0;

    for (int idx = 0; idx < total_rows; idx++) {
        int len = avg_elements_per_row + (rand() % 10) - 5; // vary between 15-25
        if (len <= 0) len = 1;
        
        SPROW* row_ptr = &(B->row[idx]);
        row_ptr->len = len;
        row_ptr->maxlen = len;
        row_ptr->diag = idx; // diagonal index
        
        row_elt* elts = (row_elt*)calloc(len, sizeof(row_elt));
        all_elts[idx] = elts;
        row_ptr->elt = elts;
        
        for (int k = 0; k < len; k++) {
            elts[k].col = (idx * 37 + k) % total_rows;
            elts[k].nxt_row = -1;
            elts[k].nxt_idx = -1;
            // Fill with non-zero values except possibly last few
            if (k == len - 1 || k == len - 2) {
                elts[k].val = 0.0;
            } else {
                elts[k].val = (double)(total_elements + 1) * 0.125;
            }
            total_elements++;
        }
    }
}