#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int size;
int x;
uint8_t *top;
uint8_t *ref_tmp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    size = (int)(data_size - 4); // Ensure x <= size and top[x-1] is valid when x=0 -> top[-1] is not accessed
    if (size < 0) size = 0;

    top = (uint8_t*)aligned_alloc(16, data_size + 1);
    ref_tmp = (uint8_t*)aligned_alloc(16, data_size);

    if (!top || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize memory to avoid undefined behavior when reading
    for (size_t i = 0; i < data_size + 1; i++) {
        top[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < data_size; i++) {
        ref_tmp[i] = 0;
    }
}