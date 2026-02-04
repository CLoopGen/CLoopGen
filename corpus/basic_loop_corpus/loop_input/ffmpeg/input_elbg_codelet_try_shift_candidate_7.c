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

elbg_data *elbg;
int idx[3];
int j;
int olderror;

void init_vars() {
    // Allocate and initialize utility array with 10 million elements to ensure sufficient data size
    // This will make the loop access valid and contribute to desired runtime
    int utility_size = 10000000;
    elbg = (elbg_data*)calloc(1, sizeof(elbg_data));
    elbg->utility = (int*)calloc(utility_size, sizeof(int));
    
    // Initialize utility values to non-zero to have effect on olderror
    for (int i = 0; i < utility_size; i++) {
        elbg->utility[i] = i & 0xFF;
    }
    
    // Ensure idx values are within bounds of utility array
    idx[0] = utility_size / 4;
    idx[1] = utility_size / 2;
    idx[2] = utility_size * 3 / 4;
    
    // Initialize other required fields to avoid potential dereferences
    elbg->dim = 3;
    elbg->numCB = 256;
    elbg->error = 0;
    
    // Allocate minimal required structures
    elbg->codebook = NULL;
    elbg->cells = NULL;
    elbg->utility_inc = NULL;
    elbg->nearest_cb = NULL;
    elbg->points = NULL;
    elbg->rand_state = NULL;
    elbg->scratchbuf = NULL;
    
    // Initialize olderror to zero
    olderror = 0;
}