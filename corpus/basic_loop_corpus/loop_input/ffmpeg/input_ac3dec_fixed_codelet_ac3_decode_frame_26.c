#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *buf;
int buf_size;
int i;

static uint8_t *internal_buf;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPUs
    internal_buf = (uint8_t*)aligned_alloc(32, buf_size);
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    buf = internal_buf;

    memset(internal_buf, 0, buf_size);

    const int pattern_xor = 119 ^ 11;
    const uint8_t val_a = 119;
    const uint8_t val_b = 11;

    size_t trigger_pos = buf_size / 2;
    if (trigger_pos % 2 == 0) trigger_pos++;

    internal_buf[trigger_pos] = val_a;
    internal_buf[trigger_pos - 1] = val_b;

    if ((internal_buf[trigger_pos] ^ internal_buf[trigger_pos - 1]) != pattern_xor) {
        internal_buf[trigger_pos] = val_a;
        internal_buf[trigger_pos - 1] = val_b;
    }
}