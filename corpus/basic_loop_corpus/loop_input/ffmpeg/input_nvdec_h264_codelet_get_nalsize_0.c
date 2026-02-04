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
    buf = (uint8_t*)malloc(data_size);
    if (!buf) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; idx++) {
        buf[idx] = rand() & 0xFF;
    }

    buf_index = (int*)malloc(sizeof(int));
    if (!buf_index) {
        free(buf);
        exit(1);
    }
    *buf_index = 0;

    i = 0;
    nalsize = 0;
    nal_length_size = 4;

    // Ensure that accessing buf[(*buf_index)++] up to nal_length_size-1 is valid
    if ((size_t)(*buf_index + nal_length_size - 1) >= data_size) {
        *buf_index = data_size - nal_length_size;
    }
}