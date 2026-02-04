#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int i;
uint8_t *dst;
uint8_t *buf;

static uint8_t *buf_storage;
static uint8_t *dst_storage;

void init_vars() {
    n = 67108864;  // 64M elements -> total access of n*2 = 128M bytes from buf, ~0.01 sec on modern CPU

    buf_storage = (uint8_t*)aligned_alloc(32, 2 * n * sizeof(uint8_t));
    dst_storage = (uint8_t*)aligned_alloc(32, n * sizeof(uint8_t));

    if (!buf_storage || !dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 2 * n; j++) {
        buf_storage[j] = rand() & 0xFF;
    }
    for (int j = 0; j < n; j++) {
        dst_storage[j] = 0;
    }

    buf = buf_storage;
    dst = dst_storage;
}