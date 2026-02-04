#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jas_seqent_t;

typedef struct {
    int flags_;
    int_fast32_t xstart_;
    int_fast32_t ystart_;
    int_fast32_t xend_;
    int_fast32_t yend_;
    int_fast32_t numrows_;
    int_fast32_t numcols_;
    jas_seqent_t **rows_;
    int_fast32_t maxrows_;
    jas_seqent_t *data_;
    int_fast32_t datasize_;
} jas_matrix_t;

typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jas_matrix_t *x;
extern jpc_fix_t absstepsize;
extern int i;
extern int j;
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val;
    jas_seqent_t **rows = (x)->rows_;
    int_fast32_t numrows = (x)->numrows_;
    int_fast32_t numcols = (x)->numcols_;
    for (i = 0; i < numrows; ++i) {
        for (j = 0; j < numcols; ++j) {
            temp_val = rows[i][j];
            if (temp_val) {
                temp_val = ((jpc_fix_t)((((jpc_fix_big_t)(temp_val)) * ((jpc_fix_big_t)(absstepsize))) >> (13)));
            }
            rows[i][j] = temp_val;
        }
        // Introduce artificial loop-carried dependency: use 'j' after inner loop as a mild control dependency
        // This does not affect correctness but creates a WAW-like pattern on 'j' across outer iterations
        if (i > 0) {
            // Dummy operation to create a weak dependence on previous iteration's j final value
            j = numcols; // Reinitialize assumption, creating a write-after-write with inner loop's j
        }
    }
}
