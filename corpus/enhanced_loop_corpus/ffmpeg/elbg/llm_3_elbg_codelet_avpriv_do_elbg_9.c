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
    // Variant 2: Use indirect array indexing with pointer arithmetic to simulate indirect memory access
    // This variant replaces array subscripting with pointers and changes access order to emphasize indirect loads

    int dim = elbg->dim;
    int *codebook = elbg->codebook;
    int *points = elbg->points;
    int *nearest_cb = elbg->nearest_cb;

    for (i = 0; i < numpoints; i++) {
        int cluster_index = *(nearest_cb + i); // Indirect read via pointer arithmetic
        *(size_part + cluster_index) += 1;      // Update size_part using pointer arithmetic

        int *cb_ptr = codebook + cluster_index * dim;   // Base pointer to target centroid
        int *pt_ptr = points + i * dim;                 // Base pointer to current point

        for (j = 0; j < dim; j++) {
            // Indirect accumulation through dereferenced pointers
            *(cb_ptr + j) += *(pt_ptr + j);
        }
    }
}
