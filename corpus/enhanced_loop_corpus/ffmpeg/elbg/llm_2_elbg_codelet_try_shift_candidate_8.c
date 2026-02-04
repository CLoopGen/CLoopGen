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

extern elbg_data *elbg;
extern int idx[3];
extern int j;
extern int k;
extern int cont;
extern int *newcentroid[3];
extern cell *tempcell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change to strided memory access pattern for 'points' array
    // Instead of accessing elements at [tempcell->index * elbg->dim + j], we precompute the base index
    // and use a stride of 1 across dimensions, improving predictability.
    int base_index;
    for (k = 0; k < 2; k++) {
        tempcell = elbg->cells[idx[2 * k]];
        while (tempcell) {  // Note: using while only for traversal, not replacing outer for
            cont++;
            base_index = tempcell->index * elbg->dim;
            for (j = 0; j < elbg->dim; j++) {
                newcentroid[2][j] += elbg->points[base_index + j];
            }
            tempcell = tempcell->next;
        }
    }
}
