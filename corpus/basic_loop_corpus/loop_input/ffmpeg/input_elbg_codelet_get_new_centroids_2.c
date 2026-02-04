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
int *min;
int *max;
int i;

void init_vars() {
    elbg = malloc(sizeof(elbg_data));
    elbg->dim = 50000000; // Large enough to take ~0.01s

    min = malloc(elbg->dim * sizeof(int));
    max = malloc(elbg->dim * sizeof(int));

    for (int j = 0; j < elbg->dim; j++) {
        min[j] = 0;
        max[j] = 0;
    }

    elbg->error = 0;
    elbg->numCB = 1;
    elbg->codebook = NULL;
    elbg->cells = NULL;
    elbg->utility = NULL;
    elbg->utility_inc = NULL;
    elbg->nearest_cb = NULL;
    elbg->points = NULL;
    elbg->rand_state = NULL;
    elbg->scratchbuf = NULL;
}