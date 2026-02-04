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
        ssize_t col = columns[j];
        ssize_t row = rows[j];
        if (col != row) {
            for (i = 0; i < (ssize_t)rank; i++) {
                long double temp = hp_matrix[i][col];
                hp_matrix[i][col] = hp_matrix[i][row];
                hp_matrix[i][row] = temp;
            }
        }
    }
}
