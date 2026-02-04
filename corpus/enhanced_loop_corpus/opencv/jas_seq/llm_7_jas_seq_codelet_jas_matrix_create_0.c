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

extern int numrows;
extern jas_matrix_t *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jas_seqent_t **rows = matrix->rows_;
    jas_seqent_t *data = matrix->data_;
    int_fast32_t numcols = matrix->numcols_;
    for (i = 0; i < numrows; ++i) {
        rows[i] = &data[i * numcols];
    }
}
