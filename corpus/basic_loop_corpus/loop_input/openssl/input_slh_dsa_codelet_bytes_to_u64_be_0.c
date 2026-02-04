#include <stdint.h>
#include <stdlib.h>

uint8_t *in;
size_t in_len;
size_t i;
uint64_t total;

static uint8_t data[1024 * 128]; // 128KB of input data

void init_vars() {
    in_len = sizeof(data);
    in = data;
    i = 0;
    total = 0;

    for (size_t idx = 0; idx < in_len; idx++) {
        data[idx] = (uint8_t)(idx & 0xFF);
    }
}