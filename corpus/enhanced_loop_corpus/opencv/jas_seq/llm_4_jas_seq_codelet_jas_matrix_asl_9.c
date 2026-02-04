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
    int i = matrix->numrows_;
    jas_seqent_t *rowstart = matrix->rows_[0];
    while (i > 0) {
        int j = matrix->numcols_;
        jas_seqent_t *data = rowstart;
        while (j > 0) {
            if (n != 0) {
                *data <<= n;
            }
            ++data;
            --j;
        }
        rowstart += rowstep;
        --i;
    }
}
