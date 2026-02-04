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
extern int huc;
extern cell *tempcell;
extern int *min;
extern int *max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and using stride of 1
    // Instead of recalculating tempcell->index * elbg->dim + i each time, we compute the base address once per cell
    cell *iter = elbg->cells[huc];
    while (iter) {
        int base_idx = iter->index * elbg->dim;
        const int *points_base = &elbg->points[base_idx];
        for (i = 0; i < elbg->dim; i++) {
            int val = points_base[i]; // Now accessing consecutively: points_base[0], points_base[1], ...
            min[i] = (min[i] < val) ? min[i] : val;
            max[i] = (max[i] > val) ? max[i] : val;
        }
        iter = iter->next;
    }
}
