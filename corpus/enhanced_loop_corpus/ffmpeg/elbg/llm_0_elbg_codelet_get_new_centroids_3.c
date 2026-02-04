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
    for (tempcell = elbg->cells[huc]; tempcell; tempcell = tempcell->next) {
        i = 0;
        if (i < elbg->dim) {
            do {
                min[i] = ((min[i]) > (elbg->points[tempcell->index * elbg->dim + i]) ? (elbg->points[tempcell->index * elbg->dim + i]) : (min[i]));
                max[i] = ((max[i]) > (elbg->points[tempcell->index * elbg->dim + i]) ? (max[i]) : (elbg->points[tempcell->index * elbg->dim + i]));
                i++;
            } while (i < elbg->dim);
        }
    }
}
