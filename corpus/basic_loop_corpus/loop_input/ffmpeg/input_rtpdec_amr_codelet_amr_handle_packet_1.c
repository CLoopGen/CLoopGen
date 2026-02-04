#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *buf;
int len;
int frames;

static uint8_t *internal_buf = NULL;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB buffer to ensure ~0.01 sec runtime on modern CPUs

    internal_buf = (uint8_t *)aligned_alloc(32, len);
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(internal_buf, 128, len); // Set all bytes to 128 (bit 7 set)
    internal_buf[len - 1] = 0;      // Ensure loop terminates: last element breaks condition (not & 128)

    buf = internal_buf;
    frames = 1; // Initial value as per loop start condition
}

__attribute__((destructor)) void cleanup() {
    if (internal_buf) {
        free(internal_buf);
    }
}