#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct cell_s {
    int index;
    struct cell_s *next;
} cell;

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct elbg_data {
    int error;
    int dim;
    int numCB;
    int *codebook;
    cell **cells;
    int *utility;
    int64_t *utility_inc;
    int *nearest_cb;
    int *points;
    AVLFG *rand_state;
    int *scratchbuf;
} elbg_data;

elbg_data *elbg;
int i;
int64_t inc;

void init_vars() {
    elbg = (elbg_data*)calloc(1, sizeof(elbg_data));
    
    elbg->numCB = 200000;
    elbg->error = 1000000;
    elbg->dim = 8;
    
    elbg->utility = (int*)calloc(elbg->numCB, sizeof(int));
    elbg->utility_inc = (int64_t*)calloc(elbg->numCB, sizeof(int64_t));
    elbg->codebook = (int*)calloc(elbg->numCB * elbg->dim, sizeof(int));
    elbg->cells = (cell**)calloc(elbg->numCB, sizeof(cell*));
    elbg->nearest_cb = (int*)calloc(elbg->numCB, sizeof(int));
    elbg->points = (int*)calloc(elbg->numCB * elbg->dim, sizeof(int));
    elbg->scratchbuf = (int*)calloc(elbg->numCB, sizeof(int));
    
    elbg->rand_state = (AVLFG*)calloc(1, sizeof(AVLFG));
    elbg->rand_state->index = 0;
    for (int j = 0; j < 64; j++) {
        elbg->rand_state->state[j] = j + 1;
    }
    
    for (int j = 0; j < elbg->numCB; j++) {
        elbg->utility[j] = (j % 100) + 1;
    }
    
    inc = 0;
}