#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

short ***array2D;
int rows = 10000;
int columns = 100;
int i;

static short **local_array2D_data;
static short *local_array2D_storage;

void init_vars() {
    array2D = (short ***)calloc(1, sizeof(short**));
    if (!array2D) exit(1);

    local_array2D_data = (short **)calloc(rows, sizeof(short*));
    if (!local_array2D_data) exit(1);

    local_array2D_storage = (short *)calloc(rows * columns, sizeof(short));
    if (!local_array2D_storage) exit(1);

    for (int r = 0; r < rows; r++) {
        local_array2D_data[r] = &local_array2D_storage[r * columns];
    }

    *array2D = local_array2D_data;
}