#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint8_t *dst;
uint8_t *src;
int init_x;
int width;
int save_upper_left;
int save_upper_right;

static uint8_t *allocated_dst;
static uint8_t *allocated_src;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB for ~0.01 sec runtime on modern CPU

    allocated_dst = aligned_alloc(32, data_size);
    allocated_src = aligned_alloc(32, data_size);

    if (!allocated_dst || !allocated_src) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    dst = allocated_dst;
    src = allocated_src;

    for (size_t i = 0; i < data_size; i++) {
        src[i] = (uint8_t)(i & 0xFF);
    }

    init_x = 1000;
    width = data_size - 1000;
    save_upper_left = 100;
    save_upper_right = 200;

    x = 0;
}