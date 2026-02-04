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
extern int olderror;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    olderror = 0;
    for (j = 0; j < 3; ++j) {
        int current_index = idx[j];
        if (current_index < elbg->numCB && current_index >= 0) {
            olderror += elbg->utility[current_index];
        } else {
            olderror += 0;
        }
    }
}
