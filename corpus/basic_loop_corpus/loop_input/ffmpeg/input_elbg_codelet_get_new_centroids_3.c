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
int huc;
cell *tempcell;
int *min;
int *max;
int i;

void init_vars() {
    elbg = (elbg_data *)calloc(1, sizeof(elbg_data));
    elbg->dim = 64;
    elbg->numCB = 4096;
    elbg->points = (int *)calloc(1UL << 24, sizeof(int));
    elbg->cells = (cell **)calloc(elbg->numCB, sizeof(cell *));
    min = (int *)calloc(elbg->dim, sizeof(int));
    max = (int *)calloc(elbg->dim, sizeof(int));

    for (int idx = 0; idx < elbg->dim; idx++) {
        min[idx] = INT32_MAX;
        max[idx] = INT32_MIN;
    }

    for (int cb_idx = 0; cb_idx < elbg->numCB; cb_idx++) {
        cell *head = NULL;
        int num_cells = 5 + (cb_idx & 31);
        for (int j = 0; j < num_cells; j++) {
            cell *c = (cell *)calloc(1, sizeof(cell));
            c->index = (cb_idx * 37 + j) % (1UL << 18);
            c->next = head;
            head = c;
        }
        elbg->cells[cb_idx] = head;
    }

    huc = 0;
}