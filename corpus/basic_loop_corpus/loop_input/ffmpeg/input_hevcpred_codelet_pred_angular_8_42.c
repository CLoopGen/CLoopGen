#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int size;
int x;
uint8_t *left;
uint8_t *ref_tmp;

void init_vars() {
    size = (1 << 20); // 1MB of data for approximately 0.01 sec runtime
    left = aligned_alloc(16, size + 1);
    ref_tmp = aligned_alloc(16, size);

    if (!left || !ref_tmp) {
        exit(1);
    }

    for (int i = 0; i <= size; i++) {
        left[i] = (uint8_t)(i & 0xFF);
    }
    for (int i = 0; i < size; i++) {
        ref_tmp[i] = 0;
    }
}