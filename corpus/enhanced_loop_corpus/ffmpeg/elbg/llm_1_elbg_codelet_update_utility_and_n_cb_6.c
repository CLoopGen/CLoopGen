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
    if (elbg->cells[idx]) {
        for (cell *temp = elbg->cells[idx]; temp; temp = temp->next) {
            elbg->nearest_cb[temp->index] = idx;
            if (!temp->next) break;
            temp = temp->next;
            elbg->nearest_cb[temp->index] = idx;
        }
    }
}
