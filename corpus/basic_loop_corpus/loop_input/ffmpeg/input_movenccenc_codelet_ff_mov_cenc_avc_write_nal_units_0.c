#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nal_length_size = 4;
uint8_t *buf_in;
int nalsize = 0;
int j = 0;

void init_vars() {
    const size_t input_size = 1 << 20; // 1MB of data
    uint8_t *data = (uint8_t *)malloc(input_size);
    if (!data) {
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        data[i] = rand() & 0xFF;
    }

    buf_in = data;
}