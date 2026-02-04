#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int mx;
uint16_t *tmp_ptr;
uint16_t *src;
int x;

static uint16_t *allocated_src;
static uint16_t *allocated_tmp_ptr;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    allocated_src = (uint16_t*)aligned_alloc(32, data_size);
    allocated_tmp_ptr = (uint16_t*)aligned_alloc(32, data_size);

    if (!allocated_src || !allocated_tmp_ptr) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(uint16_t); i++) {
        allocated_src[i] = rand() & 0xFFFF;
    }

    w = (data_size / sizeof(uint16_t)) - 1; // Ensure src[x+1] is valid when x = w-1
    mx = 17; // Arbitrary non-zero multiplier

    tmp_ptr = allocated_tmp_ptr;
    src = allocated_src;
}