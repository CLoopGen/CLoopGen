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
    int nb = elbg->nearest_cb[i];
    size_part[nb]++;
    int base_dst = nb * elbg->dim;
    int base_src = i * elbg->dim;
    for (j = 0; j < elbg->dim; j += 4) {
        if (j + 3 < elbg->dim) {
            elbg->codebook[base_dst + j]     += elbg->points[base_src + j];
            elbg->codebook[base_dst + j + 1] += elbg->points[base_src + j + 1];
            elbg->codebook[base_dst + j + 2] += elbg->points[base_src + j + 2];
            elbg->codebook[base_dst + j + 3] += elbg->points[base_src + j + 3];
        } else {
            for (; j < elbg->dim; j++) {
                elbg->codebook[base_dst + j] += elbg->points[base_src + j];
            }
        }
    }
}
}
