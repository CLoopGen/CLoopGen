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
int idx;
int len;
int lim;
double sum;
double *x_ve;
SPROW *r;
row_elt *elt;

void init_vars() {
    const int DATA_SIZE_MB = 64;
    const int approx_elements = (DATA_SIZE_MB * 1024 * 1024) / sizeof(double);
    
    lim = approx_elements > 10000 ? 10000 : approx_elements;
    
    x_ve = (double*)calloc(lim, sizeof(double));
    if (!x_ve) exit(1);
    
    A = (SPMAT*)malloc(sizeof(SPMAT));
    if (!A) exit(1);
    
    A->m = lim;
    A->n = lim;
    A->max_m = lim;
    A->max_n = lim;
    A->flag_col = 0;
    A->flag_diag = 1;
    
    A->row = (SPROW*)calloc(lim, sizeof(SPROW));
    if (!A->row) exit(1);
    
    A->start_row = (int*)calloc(lim, sizeof(int));
    if (!A->start_row) exit(1);
    
    A->start_idx = (int*)calloc(lim, sizeof(int));
    if (!A->start_idx) exit(1);
    
    size_t total_elts = 0;
    for (i = 0; i < lim; i++) {
        A->start_row[i] = total_elts;
        int row_len = (i + 1) / 8 + 1;
        if (row_len > i) row_len = i;
        if (row_len < 0) row_len = 0;
        
        A->row[i].len = row_len;
        A->row[i].maxlen = row_len;
        A->row[i].diag = i;
        
        if (row_len > 0) {
            A->row[i].elt = (row_elt*)malloc(row_len * sizeof(row_elt));
            if (!A->row[i].elt) exit(1);
            
            for (idx = 0; idx < row_len; idx++) {
                A->row[i].elt[idx].col = idx;
                A->row[i].elt[idx].nxt_row = 0;
                A->row[i].elt[idx].nxt_idx = 0;
                A->row[i].elt[idx].val = 0.1 + (double)(i + idx) / 1000.0;
            }
        } else {
            A->row[i].elt = NULL;
        }
        
        total_elts += row_len;
    }
    
    for (i = 0; i < lim; i++) {
        x_ve[i] = 1.0 + i * 0.01;
    }
}