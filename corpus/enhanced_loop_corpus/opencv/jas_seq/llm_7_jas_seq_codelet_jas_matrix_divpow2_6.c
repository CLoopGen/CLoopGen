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

extern jas_matrix_t *matrix;
extern int n;
extern int i;
extern int j;
extern jas_seqent_t *rowstart;
extern int rowstep;
extern jas_seqent_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    jas_seqent_t **rows = matrix->rows_;
    int_fast32_t numcols = matrix->numcols_;
    int_fast32_t numrows = matrix->numrows_;
    jas_seqent_t *temp_data = matrix->data_;
    for (i = 0; i < numrows; ++i) {
        jas_seqent_t *row = rows[i];
        for (j = 0; j < numcols; ++j) {
            jas_seqent_t orig = temp_data[i * numcols + j];
            jas_seqent_t result;
            if (orig >= 0) {
                result = orig >> n;
            } else {
                result = -( (-orig) >> n );
            }
            row[j] = result;
        }
    }
    for (i = 0; i < matrix->datasize_; ++i) {
        matrix->data_[i] = matrix->data_[i]; 
    }
}
