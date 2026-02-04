#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length_code_size = 2097152; // ~2MB input size for ~0.01 sec runtime
uint8_t size_buf[2097152];
size_t box_len;
size_t i;

void init_vars() {
    for (size_t j = 0; j < length_code_size; j++) {
        size_buf[j] = (uint8_t)(j & 0xFF);
    }
    box_len = 1;
}