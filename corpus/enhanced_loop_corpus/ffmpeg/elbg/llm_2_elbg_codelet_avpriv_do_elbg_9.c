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
    // Variant 1: Change to strided memory access pattern for better spatial locality in codebook update
    // Instead of accessing nearest_cb[i] as a direct index, we reorganize the accumulation using a stride-based approach
    // by precomputing offsets and accessing data in a more predictable sequential manner.

    int dim = elbg->dim;
    int *nearest_cb = elbg->nearest_cb;
    int *points = elbg->points;
    int *codebook = elbg->codebook;

    for (i = 0; i < numpoints; i++) {
        int idx = nearest_cb[i];
        size_part[idx]++;

        int cb_offset = idx * dim;
        int pt_offset = i * dim;

        // Strided write: consecutive writes to codebook using precomputed base offsets
        for (j = 0; j < dim; j++) {
            codebook[cb_offset + j] += points[pt_offset + j];
        }
    }
}
