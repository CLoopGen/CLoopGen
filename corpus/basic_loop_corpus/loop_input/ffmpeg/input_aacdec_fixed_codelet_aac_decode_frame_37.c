#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int buf_consumed;
int buf_offset;

void init_vars() {
    buf_size = 134217728; // 128 MB to target ~0.01 sec runtime on modern CPU
    buf_consumed = 0;
    buf = (uint8_t*)calloc(buf_size, sizeof(uint8_t));
    if (!buf) exit(1);

    // Set a non-zero value near the end to ensure loop runs most of the way
    buf[buf_size - 1] = 1;
}