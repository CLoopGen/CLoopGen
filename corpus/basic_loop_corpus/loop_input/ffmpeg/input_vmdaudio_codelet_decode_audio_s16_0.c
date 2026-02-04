#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

int16_t *out;
uint8_t *buf;
int channels;
int ch;
int predictor[2];

void init_vars() {
    channels = 2;
    size_t total_data_size = 134217728; // ~128MB of input data (64M samples per channel, 2 bytes each)
    size_t buf_size = total_data_size;

    buf = (uint8_t *)aligned_alloc(16, buf_size);
    if (!buf) {
        exit(1);
    }

    out = (int16_t *)aligned_alloc(16, total_data_size);
    if (!out) {
        free(buf);
        exit(1);
    }

    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = rand() & 0xFF;
    }

    ch = 0;
    predictor[0] = 0;
    predictor[1] = 0;
}