#include <stdint.h>
#include <stdlib.h>

uint8_t *in;
int in_len;
uint64_t digit;

static uint8_t in_array[131072]; // 128KB input data

void init_vars() {
    in_len = 131072;
    in = in_array;
    digit = 0;

    for (int i = 0; i < in_len; i++) {
        in[i] = (uint8_t)(i & 0xFF);
    }
}