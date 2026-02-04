#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nal_length_size = 4;
uint8_t *buf;
int *buf_index;
int i;
int nalsize;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    buf = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    buf_index = (int *)malloc(sizeof(int));
    if (!buf_index) {
        fprintf(stderr, "Memory allocation failed\n");
        free(buf);
        exit(1);
    }

    *buf_index = 0;

    for (size_t idx = 0; idx < data_size; idx++) {
        buf[idx] = rand() & 0xFF;
    }

    nal_length_size = 4;
    nalsize = 0;
}