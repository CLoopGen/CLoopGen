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
int *newcentroid_i;
int *newcentroid_p;
int *min;
int *max;
int i;

void init_vars() {
    elbg = (elbg_data *)calloc(1, sizeof(elbg_data));
    if (!elbg) exit(1);

    elbg->dim = 65536; // Adjusted for ~0.01 sec runtime

    newcentroid_i = (int *)calloc(elbg->dim, sizeof(int));
    newcentroid_p = (int *)calloc(elbg->dim, sizeof(int));
    min = (int *)calloc(elbg->dim, sizeof(int));
    max = (int *)calloc(elbg->dim, sizeof(int));

    if (!newcentroid_i || !newcentroid_p || !min || !max) exit(1);

    for (int j = 0; j < elbg->dim; j++) {
        min[j] = 100 + j % 900;
        max[j] = min[j] + 100 + (j % 100);
    }

    elbg->codebook = NULL;
    elbg->cells = NULL;
    elbg->utility = NULL;
    elbg->utility_inc = NULL;
    elbg->nearest_cb = NULL;
    elbg->points = NULL;
    elbg->rand_state = NULL;
    elbg->scratchbuf = NULL;
    elbg->error = 0;
    elbg->numCB = 0;
}