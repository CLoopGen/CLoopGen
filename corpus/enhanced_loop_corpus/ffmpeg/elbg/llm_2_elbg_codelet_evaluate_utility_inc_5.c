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
    // Variant 1: Strided memory access pattern
    int stride = 2;
    int n = elbg->numCB;
    inc = 0; // Reset inc as side effect behavior may depend on it
    for (i = 0; i < n; i += stride) {
        int j = i;
        if (j < n && elbg->numCB * elbg->utility[j] > elbg->error)
            inc += elbg->utility[j];
        elbg->utility_inc[j] = inc;

        int k = i + 1;
        if (k < n) {
            if (elbg->numCB * elbg->utility[k] > elbg->error)
                inc += elbg->utility[k];
            elbg->utility_inc[k] = inc;
        }
    }
}
