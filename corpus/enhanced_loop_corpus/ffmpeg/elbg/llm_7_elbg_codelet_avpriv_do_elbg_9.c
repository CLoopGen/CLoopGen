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
        int local_idx = elbg->nearest_cb[i];
        int offset = local_idx * elbg->dim;
        size_part[local_idx]++;

        // Introduce temporary accumulation to remove immediate write-write dependency on codebook
        // and convert to reduction-like pattern with local temporaries (simulated unrolling effect)
        for (j = 0; j < elbg->dim; j += 4) {
            int limit = (j + 4 > elbg->dim) ? elbg->dim : j + 4;
            for (int k = j; k < limit; k++) {
                elbg->scratchbuf[k] = elbg->points[i * elbg->dim + k];  // Use scratch to stage reads
            }
            for (int k = j; k < limit; k++) {
                elbg->codebook[local_idx * elbg->dim + k] += elbg->scratchbuf[k];
            }
        }
    }
}
