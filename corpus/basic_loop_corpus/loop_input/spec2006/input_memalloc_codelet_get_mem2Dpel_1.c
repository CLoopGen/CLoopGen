#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short ***array2D;
int rows = 16384;
int columns = 4096;
int i;

void init_vars() {
    // Allocate array2D: a pointer to a pointer to a pointer
    array2D = (unsigned short ***)malloc(sizeof(unsigned short **));
    if (!array2D) exit(1);

    // Allocate array of row pointers: points to first level of 2D array
    unsigned short **rows_ptr = (unsigned short **)calloc(rows, sizeof(unsigned short *));
    if (!rows_ptr) exit(1);
    *array2D = rows_ptr;

    // Allocate contiguous memory block for all elements
    unsigned short *data_block = (unsigned short *)malloc(rows * columns * sizeof(unsigned short));
    if (!data_block) exit(1);

    // Initialize each row pointer to the correct offset
    for (int r = 0; r < rows; r++) {
        (*array2D)[r] = data_block + r * columns;
    }
}