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
    buf = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buf) {
        exit(1);
    }
    buf_index = (int*)malloc(sizeof(int));
    if (!buf_index) {
        free(buf);
        exit(1);
    }
    *buf_index = 0;
    for (size_t j = 0; j < data_size; j++) {
        buf[j] = rand() & 0xFF;
    }
    nal_length_size = 4; // Ensure we read 4 bytes for nalsize
    if (data_size < nal_length_size) {
        exit(1);
    }
}