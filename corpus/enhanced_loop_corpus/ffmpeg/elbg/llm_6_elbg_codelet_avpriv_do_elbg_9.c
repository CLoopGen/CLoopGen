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
    int *nearest_cb = elbg->nearest_cb;
    int *points = elbg->points;
    int *codebook = elbg->codebook;
    int dim = elbg->dim;

    for (i = 0; i < numpoints; i++) {
        int idx = nearest_cb[i];
        size_part[idx]++;
        int base_codebook = idx * dim;
        int base_points = i * dim;
        for (j = 0; j < dim; j++) {
            codebook[base_codebook + j] += points[base_points + j];
        }
    }
}
