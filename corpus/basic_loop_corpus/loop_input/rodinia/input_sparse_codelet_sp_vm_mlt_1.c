#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
int j_idx;
int m;
int max_idx;
double tmp;
double *x_ve;
double *out_ve;
SPROW *r;
row_elt *elts;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(row_elt))

void init_vars() {
    const int num_rows = 8000;
    const int avg_elements_per_row = TOTAL_ELEMENTS / num_rows;
    const int padding = 10;
    
    m = num_rows;
    A = (SPMAT*)calloc(1, sizeof(SPMAT));
    A->m = m;
    A->n = num_rows; 
    A->max_m = m;
    A->max_n = num_rows;
    A->flag_col = 0;
    A->flag_diag = 1;
    
    A->row = (SPROW*)calloc(m, sizeof(SPROW));
    A->start_row = (int*)calloc(m, sizeof(int));
    A->start_idx = (int*)calloc(m, sizeof(int));
    
    x_ve = (double*)calloc(m, sizeof(double));
    out_ve = (double*)calloc(m, sizeof(double));
    
    srand(12345);
    
    int total_elts = 0;
    for (i = 0; i < m; i++) {
        int len = avg_elements_per_row + rand() % (padding * 2) - padding;
        if (len <= 0) len = 1;
        if (total_elts + len > TOTAL_ELEMENTS) {
            len = (TOTAL_ELEMENTS - total_elts > 0) ? TOTAL_ELEMENTS - total_elts : 1;
        }
        if (len <= 0) break;
        
        A->row[i].len = len;
        A->row[i].maxlen = len;
        A->row[i].diag = i; 
        A->row[i].elt = (row_elt*)calloc(len, sizeof(row_elt));
        
        for (j_idx = 0; j_idx < len; j_idx++) {
            A->row[i].elt[j_idx].col = rand() % m;
            A->row[i].elt[j_idx].nxt_row = (i + 1) % m;
            A->row[i].elt[j_idx].nxt_idx = j_idx;
            A->row[i].elt[j_idx].val = 1.0 + (rand() % 1000) / 1000.0;
        }
        
        x_ve[i] = 1.0 + (rand() % 1000) / 1000.0;
        total_elts += len;
        if (total_elts >= TOTAL_ELEMENTS) break;
    }
    
    for (; i < m; i++) {
        A->row[i].len = 1;
        A->row[i].maxlen = 1;
        A->row[i].diag = i;
        A->row[i].elt = (row_elt*)calloc(1, sizeof(row_elt));
        A->row[i].elt[0].col = i % m;
        A->row[i].elt[0].val = 1.0;
    }
}