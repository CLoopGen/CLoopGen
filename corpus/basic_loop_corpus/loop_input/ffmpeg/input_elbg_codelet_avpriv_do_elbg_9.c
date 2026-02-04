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

int numpoints;
elbg_data *elbg;
int i;
int j;
int *size_part;

void init_vars() {
    numpoints = 1000000;  // ~1M points to achieve ~0.01s runtime

    elbg = (elbg_data*)calloc(1, sizeof(elbg_data));
    elbg->dim = 3;
    elbg->numCB = 100;
    elbg->error = 0;

    // Allocate and initialize nearest_cb: each point assigned to a valid codebook index
    elbg->nearest_cb = (int*)malloc(numpoints * sizeof(int));
    for (int idx = 0; idx < numpoints; idx++) {
        elbg->nearest_cb[idx] = rand() % elbg->numCB;
    }

    // Points: numpoints * dim
    elbg->points = (int*)malloc(numpoints * elbg->dim * sizeof(int));
    for (int idx = 0; idx < numpoints * elbg->dim; idx++) {
        elbg->points[idx] = rand() % 256;
    }

    // Codebook: numCB * dim
    elbg->codebook = (int*)malloc(elbg->numCB * elbg->dim * sizeof(int));
    for (int idx = 0; idx < elbg->numCB * elbg->dim; idx++) {
        elbg->codebook[idx] = 0;
    }

    // size_part: one count per codebook entry
    size_part = (int*)calloc(elbg->numCB, sizeof(int));

    // Optional fields not used in loop but allocated to avoid null deref if accessed elsewhere
    elbg->cells = (cell**)calloc(elbg->numCB, sizeof(cell*));
    elbg->utility = (int*)calloc(elbg->numCB, sizeof(int));
    elbg->utility_inc = (int64_t*)calloc(elbg->numCB, sizeof(int64_t));
    elbg->rand_state = (AVLFG*)calloc(1, sizeof(AVLFG));
    elbg->rand_state->index = 0;
    elbg->scratchbuf = (int*)malloc(elbg->dim * sizeof(int));

    // Initialize AVLFG state
    for (int k = 0; k < 64; k++) {
        elbg->rand_state->state[k] = rand();
    }
}