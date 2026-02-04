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
    if (elbg->cells[huc]) {
        for (tempcell = elbg->cells[huc]; tempcell; tempcell = tempcell->next) {
            for (i = 0; i < elbg->dim; i++) {
                int point_val = elbg->points[tempcell->index * elbg->dim + i];
                if (point_val < min[i]) {
                    min[i] = point_val;
                }
                if (point_val > max[i]) {
                    max[i] = point_val;
                }
            }
        }
    }
}
