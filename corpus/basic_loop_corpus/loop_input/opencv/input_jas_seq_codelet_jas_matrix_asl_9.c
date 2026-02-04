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

jas_matrix_t *matrix;
int n;
int i;
int j;
jas_seqent_t *rowstart;
int rowstep;
jas_seqent_t *data;

static jas_seqent_t* allocated_data = 0;
static jas_seqent_t** matrix_rows = 0;

void init_vars() {
    const int numrows = 8192;
    const int numcols = 8192;
    const int total_size = numrows * numcols;

    n = 1;

    allocated_data = (jas_seqent_t*)calloc(total_size, sizeof(jas_seqent_t));
    if (!allocated_data) exit(1);

    matrix_rows = (jas_seqent_t**)malloc(numrows * sizeof(jas_seqent_t*));
    if (!matrix_rows) exit(1);

    for (int r = 0; r < numrows; ++r) {
        matrix_rows[r] = allocated_data + r * numcols;
    }

    matrix = (jas_matrix_t*)malloc(sizeof(jas_matrix_t));
    if (!matrix) exit(1);

    matrix->numrows_ = numrows;
    matrix->numcols_ = numcols;
    matrix->rows_ = matrix_rows;
    matrix->data_ = allocated_data;
    matrix->datasize_ = total_size;
    matrix->xstart_ = 0;
    matrix->ystart_ = 0;
    matrix->xend_ = numcols - 1;
    matrix->yend_ = numrows - 1;
    matrix->flags_ = 0;
    matrix->maxrows_ = numrows;

    rowstep = numcols;
    rowstart = 0;
    data = 0;
}