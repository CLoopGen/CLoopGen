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
int k;
for (i = 0; i < numpoints; i += 2) {
    int nb0 = elbg->nearest_cb[i];
    size_part[nb0]++;
    for (j = 0; j < elbg->dim; j++) {
        int idx = nb0 * elbg->dim + j;
        elbg->codebook[idx] += elbg->points[i * elbg->dim + j];
    }
    if (i + 1 < numpoints) {
        int nb1 = elbg->nearest_cb[i + 1];
        size_part[nb1]++;
        for (j = 0; j < elbg->dim; j++) {
            int idx = nb1 * elbg->dim + j;
            elbg->codebook[idx] += elbg->points[(i + 1) * elbg->dim + j];
        }
    }
}
}
