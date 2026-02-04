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
    cell *iter = elbg->cells[idx];
    int *ncb = elbg->nearest_cb;
    int write_offset = 0;
    for (; iter != NULL; iter = iter->next, write_offset++) {
        ncb[iter->index + write_offset - write_offset] = idx;
    }
}
