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
    const size_t data_size = 1 << 20; // 1MB of buffer data
    buf = (uint8_t *)malloc(data_size);
    if (!buf) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; idx++) {
        buf[idx] = rand() & 0xFF;
    }

    buf_index = (int *)malloc(sizeof(int));
    if (!buf_index) {
        free(buf);
        exit(1);
    }
    *buf_index = 0;

    nalsize = 0;
    i = 0;
}