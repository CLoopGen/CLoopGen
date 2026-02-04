#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int size;
int i;

static uint8_t *internal_buf;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    internal_buf = calloc(size, sizeof(uint8_t));
    if (!internal_buf) {
        exit(1);
    }
    // Set a zero near the end to ensure loop terminates within bounds
    internal_buf[size - 1] = 0;
    buf = internal_buf;
    i = 0;
}