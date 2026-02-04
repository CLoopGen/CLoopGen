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

static jas_seqent_t** allocated_rows;
static jas_seqent_t* allocated_data;

void init_vars() {
    const size_t target_size_bytes = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on modern CPU
    const size_t elem_size = sizeof(jas_seqent_t);
    size_t total_elements = target_size_bytes / elem_size;
    
    // Choose square-ish matrix dimensions
    matrix->numrows_ = (int_fast32_t)(total_elements / 512);
    if (matrix->numrows_ == 0) matrix->numrows_ = 1;
    matrix->numcols_ = (int_fast32_t)(total_elements / matrix->numrows_);
    
    matrix->maxrows_ = matrix->numrows_;
    matrix->datasize_ = matrix->numrows_ * matrix->numcols_;
    
    // Allocate data buffer
    allocated_data = calloc(matrix->datasize_, elem_size);
    if (!allocated_data) abort();
    
    // Allocate rows array
    allocated_rows = malloc(matrix->numrows_ * sizeof(jas_seqent_t*));
    if (!allocated_rows) abort();
    
    // Set up row pointers with stride equal to numcols_
    for (int r = 0; r < matrix->numrows_; ++r) {
        allocated_rows[r] = &allocated_data[r * matrix->numcols_];
    }
    
    // Initialize matrix fields
    matrix->rows_ = allocated_rows;
    matrix->data_ = allocated_data;
    matrix->xstart_ = 0;
    matrix->ystart_ = 0;
    matrix->xend_ = matrix->numcols_ - 1;
    matrix->yend_ = matrix->numrows_ - 1;
    matrix->flags_ = 0;
    
    // Initialize other globals
    n = 2; // reasonable shift amount
    rowstep = matrix->numcols_; // contiguous rows
    rowstart = 0;
    data = 0;
}

// Define matrix after declaration so we can allocate it in init_vars
static jas_matrix_t _matrix_instance;
jas_matrix_t *matrix = &_matrix_instance;