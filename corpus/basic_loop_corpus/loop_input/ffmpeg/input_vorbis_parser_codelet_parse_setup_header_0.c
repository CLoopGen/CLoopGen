#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
uint8_t *rev_buf;
int i;

void init_vars() {
    buf_size = 134217728; // 128 MB to target ~0.01 sec on modern CPUs

    buf = (uint8_t*)aligned_alloc(32, buf_size);
    rev_buf = (uint8_t*)aligned_alloc(32, buf_size);

    if (!buf || !rev_buf) {
        exit(1);
    }

    for (int j = 0; j < buf_size; j++) {
        buf[j] = (uint8_t)(j & 0xFF);
    }
}