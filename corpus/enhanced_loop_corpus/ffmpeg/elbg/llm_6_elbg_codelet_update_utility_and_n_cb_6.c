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
extern int idx;
extern cell *tempcell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    cell *current = elbg->cells[idx];
    int local_idx = idx;
    while (1) {
        if (!current) break;
        int temp_index = current->index;
        elbg->nearest_cb[temp_index] = local_idx;
        current = current->next;
    }
}
