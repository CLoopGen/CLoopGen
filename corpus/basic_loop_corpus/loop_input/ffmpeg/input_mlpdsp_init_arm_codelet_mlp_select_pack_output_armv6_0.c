#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *ch_assign;
int8_t *output_shift;
uint8_t max_matrix_channel;
int shift;
int inorder;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data

    ch_assign = (uint8_t *)malloc(data_size);
    output_shift = (int8_t *)malloc(data_size);

    if (!ch_assign || !output_shift) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        ch_assign[idx] = (uint8_t)(idx % 256);
        output_shift[idx] = (int8_t)((idx % 255) - 127);
    }

    max_matrix_channel = (uint8_t)((data_size / sizeof(uint8_t)) - 1);
    shift = 5;
    inorder = 1;
}