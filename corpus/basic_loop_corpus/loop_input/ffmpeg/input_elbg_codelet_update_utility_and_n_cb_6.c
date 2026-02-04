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
int idx;
cell *tempcell;

static cell **g_cells = NULL;
static int *g_nearest_cb = NULL;
static cell *g_cell_pool = NULL;

void init_vars() {
    const int numCB = 1024;
    const int max_points_per_cell = 100000;
    const int total_cells = numCB;
    const int total_points = numCB * max_points_per_cell;

    g_cells = (cell**)calloc(numCB, sizeof(cell*));
    g_nearest_cb = (int*)calloc(total_points, sizeof(int));
    g_cell_pool = (cell*)calloc(total_points, sizeof(cell));

    if (!g_cells || !g_nearest_cb || !g_cell_pool) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    int point_idx = 0;
    for (int i = 0; i < total_cells; i++) {
        cell* head = NULL;
        int count = rand() % max_points_per_cell + 1;
        for (int j = 0; j < count; j++) {
            cell* new_cell = &g_cell_pool[point_idx++];
            new_cell->index = point_idx - 1;
            new_cell->next = head;
            head = new_cell;
        }
        g_cells[i] = head;
    }

    elbg = (elbg_data*)malloc(sizeof(elbg_data));
    if (!elbg) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    elbg->numCB = numCB;
    elbg->cells = g_cells;
    elbg->nearest_cb = g_nearest_cb;
    elbg->points = NULL;
    elbg->codebook = NULL;
    elbg->utility = NULL;
    elbg->utility_inc = NULL;
    elbg->rand_state = NULL;
    elbg->scratchbuf = NULL;
    elbg->dim = 0;
    elbg->error = 0;

    idx = rand() % numCB;
}