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
        int idx = elbg->nearest_cb[i];
        size_part[idx]++;
        int base1 = idx * elbg->dim;
        int base2 = i * elbg->dim;
        for (j = 0; j < elbg->dim; j++) {
            elbg->codebook[base1 + j] += elbg->points[base2 + j];
        }
    }
}
