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
    int stride = elbg->dim;
    int limit = stride * 2;
    for (tempcell = elbg->cells[huc]; tempcell; tempcell = tempcell->next) {
        int base_idx = tempcell->index * elbg->dim;
        for (i = 0; i < limit; i += 2) {
            int idx1 = base_idx + i;
            int idx2 = (i + 1 < stride) ? base_idx + i + 1 : base_idx + i;
            int val1 = elbg->points[idx1];
            int val2 = (i + 1 < stride) ? elbg->points[idx2] : val1;

            min[i / 2] = (min[i / 2] < val1) ? min[i / 2] : val1;
            max[i / 2] = (max[i / 2] > val1) ? max[i / 2] : val1;

            if (i + 1 < stride) {
                min[i / 2] = (min[i / 2] < val2) ? min[i / 2] : val2;
                max[i / 2] = (max[i / 2] > val2) ? max[i / 2] : val2;
            }
        }
    }
}
