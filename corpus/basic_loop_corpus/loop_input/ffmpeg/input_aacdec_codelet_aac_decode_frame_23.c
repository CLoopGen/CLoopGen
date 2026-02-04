#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int buf_consumed;
int buf_offset;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    buf_consumed = 0;
    buf = aligned_alloc(32, buf_size);
    if (!buf) exit(1);

    // Fill buffer with zeros except last byte to force worst-case scan
    for (int i = 0; i < buf_size - 1; i++) {
        buf[i] = 0;
    }
    buf[buf_size - 1] = 1; // Ensures loop breaks at last element
}