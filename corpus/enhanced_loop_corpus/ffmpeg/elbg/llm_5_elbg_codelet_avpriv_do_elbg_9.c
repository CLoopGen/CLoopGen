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

extern int numpoints;
extern elbg_data *elbg;
extern int i;
extern int j;
extern int *size_part;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < numpoints; i++) {
    int nc = elbg->nearest_cb[i];
    size_part[nc]++;
    j = 0;
    for (; j < elbg->dim; j += 2) {
        int idx1 = i * elbg->dim + j;
        int idx2 = nc * elbg->dim + j;
        elbg->codebook[idx2] += elbg->points[idx1];
        if (j + 1 < elbg->dim) {
            elbg->codebook[idx2 + 1] += elbg->points[idx1 + 1];
        }
    }
}
}
