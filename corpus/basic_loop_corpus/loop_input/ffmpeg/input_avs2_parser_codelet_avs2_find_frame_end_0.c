#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *buf;
int buf_size;
int pic_found;
uint32_t state;
int cur;

static uint8_t *internal_buf;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    internal_buf = (uint8_t *)malloc(buf_size);
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random data, but ensure no trigger byte sequence appears early
    srand(time(NULL));
    for (int i = 0; i < buf_size; ++i) {
        uint8_t val;
        do {
            val = rand() % 256;
        } while (val == 176 || val == 177 || val == 178 || val == 179 || val == 182);
        internal_buf[i] = val;
    }

    // Place a matching byte near the end to ensure loop terminates naturally
    if (buf_size > 1) {
        internal_buf[buf_size - 1] = 176;
    }

    buf = internal_buf;
    pic_found = 0;
    state = 0;
    cur = 0;
}