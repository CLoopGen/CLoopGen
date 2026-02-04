#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t rank;
extern long double **hp_matrix;
extern ssize_t *columns;
extern ssize_t i;
extern ssize_t j;
extern ssize_t *rows;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using consecutive access via pointer arithmetic
    long double *col_ptr = (long double *)hp_matrix;
    long double *row_ptr = (long double *)hp_matrix;

    for (j = (ssize_t)rank - 1; j >= 0; j--) {
        if (columns[j] != rows[j]) {
            ssize_t col_offset = columns[j];
            ssize_t row_offset = rows[j];

            for (i = 0; i < (ssize_t)rank; i++) {
                long double temp = col_ptr[i * (ssize_t)rank + col_offset];
                col_ptr[i * (ssize_t)rank + col_offset] = row_ptr[i * (ssize_t)rank + row_offset];
                row_ptr[i * (ssize_t)rank + row_offset] = temp;
            }
        }
    }
}
