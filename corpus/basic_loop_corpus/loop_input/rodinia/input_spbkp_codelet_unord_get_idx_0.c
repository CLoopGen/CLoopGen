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

SPROW *r;
int j;
int idx;
row_elt *e;

#define DATA_SIZE_MB 64
#define NUM_ELTS (DATA_SIZE_MB * (1<<20) / sizeof(row_elt))

static row_elt elts[NUM_ELTS];

void init_vars() {
    for (int i = 0; i < NUM_ELTS; i++) {
        elts[i].col = i + 1;
        elts[i].nxt_row = 0;
        elts[i].nxt_idx = 0;
        elts[i].val = 1.0 / (i + 1);
    }
    
    r = (SPROW*)malloc(sizeof(SPROW));
    r->len = NUM_ELTS - 1;
    r->maxlen = NUM_ELTS;
    r->diag = 0;
    r->elt = elts;
    
    j = NUM_ELTS; 
    idx = 0;
    e = NULL;
}