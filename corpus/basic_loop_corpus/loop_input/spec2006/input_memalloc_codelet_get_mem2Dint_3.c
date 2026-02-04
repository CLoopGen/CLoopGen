#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***array2D;
int rows = 10000;
int columns = 1000;
int i;

static int **ptr_array;
static int *data;

void init_vars() {
    data = (int *)calloc(rows * columns, sizeof(int));
    ptr_array = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) {
        ptr_array[r] = &data[r * columns];
    }
    array2D = (int ***)malloc(sizeof(int **));
    *array2D = ptr_array;
}