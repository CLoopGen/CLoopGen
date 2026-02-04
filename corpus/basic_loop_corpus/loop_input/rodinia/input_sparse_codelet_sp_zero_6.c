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

SPMAT *A;
int i;
int idx;
int len;
row_elt *elt;

static SPROW *rows;
static row_elt **elts;
static int total_elements = 0;

void init_vars() {
    // Target approximately 64MB of data to ensure ~0.01s runtime on modern CPU
    const int rows_per_block = 10000;
    const int avg_elements_per_row = 8;
    const int total_rows = rows_per_block;
    const int total_elts = total_rows * avg_elements_per_row;
    
    // Allocate main structures
    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    rows = (SPROW*)calloc(total_rows, sizeof(SPROW));
    elts = (row_elt**)calloc(total_rows, sizeof(row_elt*));
    
    // Allocate combined element storage in one block for cache efficiency
    row_elt* all_elts = (row_elt*)calloc(total_elts, sizeof(row_elt));
    
    // Initialize A
    A->m = total_rows;
    A->n = total_rows;  // square-like assumption
    A->max_m = total_rows;
    A->max_n = total_rows;
    A->flag_col = 0;
    A->flag_diag = 1;
    A->row = rows;
    A->start_row = NULL;
    A->start_idx = NULL;
    
    // Initialize each row
    row_elt* current_ptr = all_elts;
    for (i = 0; i < total_rows; i++) {
        int row_len = avg_elements_per_row; // Fixed for simplicity and predictability
        
        rows[i].len = row_len;
        rows[i].maxlen = row_len;
        rows[i].diag = i;  // diagonal index
        rows[i].elt = current_ptr;
        
        // Initialize elements in this row
        for (idx = 0; idx < row_len; idx++) {
            current_ptr[idx].col = (i + idx) % total_rows;
            current_ptr[idx].nxt_row = -1;
            current_ptr[idx].nxt_idx = -1;
            current_ptr[idx].val = 1.0; // Non-zero initial value
        }
        
        current_ptr += row_len;
    }
    
    total_elements = total_elts;
}