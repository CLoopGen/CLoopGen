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

int lim;
row_elt *elts;
int idx;
int len;
double sum;
double tmp;

#define DATA_SIZE_MB 64
#define NUM_ELTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(row_elt))

static row_elt elts_buffer[NUM_ELTS];

void init_vars() {
    len = NUM_ELTS;
    lim = NUM_ELTS / 2; 
    idx = 0;
    sum = 0.0;
    tmp = 0.0;
    elts = elts_buffer;

    for (int i = 0; i < len; i++) {
        elts_buffer[i].col = i;
        elts_buffer[i].nxt_row = i + 1;
        elts_buffer[i].nxt_idx = i + 1;
        elts_buffer[i].val = (double)(i % 1000) / 100.0;
    }
}