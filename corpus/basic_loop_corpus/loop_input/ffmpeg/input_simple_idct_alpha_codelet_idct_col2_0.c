#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *col;
int i;

static int16_t *col_data;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of int16_t: 524,288 elements
    col_data = (int16_t *)calloc(data_size, sizeof(int16_t));
    if (!col_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        col_data[idx] = rand() % 65536 - 32768;
    }

    col = col_data;
    i = 0;
}