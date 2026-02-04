#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int ey = 1023;
int stride = 1024;
int color = 128;
int x;
int y;
int fr;
int f = 65536;

void init_vars() {
    const size_t buf_size = 1024 * 1024; // 1MB buffer
    buf = aligned_alloc(32, buf_size);
    if (!buf) {
        exit(1);
    }
    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = rand() & 0xFF;
    }
}