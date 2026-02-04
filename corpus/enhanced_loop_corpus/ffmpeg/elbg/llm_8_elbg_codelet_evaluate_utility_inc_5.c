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
extern int i;
extern int64_t inc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_inc = inc;
    for (i = 0; i < elbg->numCB; i += 2) {
        int cond1 = (elbg->numCB * elbg->utility[i] > elbg->error);
        int cond2 = (i + 1 < elbg->numCB) && (elbg->numCB * elbg->utility[i + 1] > elbg->error);
        
        if (cond1)
            local_inc += elbg->utility[i];
        if (cond2)
            local_inc += elbg->utility[i + 1];
        
        elbg->utility_inc[i] = local_inc;
        if (i + 1 < elbg->numCB)
            elbg->utility_inc[i + 1] = local_inc;
    }
    inc = local_inc;
}
