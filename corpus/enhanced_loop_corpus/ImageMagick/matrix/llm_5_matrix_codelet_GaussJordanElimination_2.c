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
for (j = (ssize_t)rank - 1; j >= 0; j--) {
    ssize_t diff = columns[j] - rows[j];
    if (diff != 0) {
        for (i = 0; i < (ssize_t)rank; i++) {
            long double *row_i = hp_matrix[i];
            long double temp = row_i[columns[j]];
            row_i[columns[j]] = row_i[rows[j]];
            row_i[rows[j]] = temp;
        }
    }
}
}
