#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int size;
int x;
uint16_t *left;
uint16_t *ref_tmp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    size = (data_size / sizeof(uint16_t)) - 1; // Ensure valid access at boundaries

    left = aligned_alloc(64, (size + 2) * sizeof(uint16_t));
    ref_tmp = aligned_alloc(64, (size + 4) * sizeof(uint16_t));

    if (!left || !ref_tmp) {
        exit(1);
    }

    for (int i = 0; i <= size + 1; ++i) {
        left[i] = i & 0xFFFF;
    }
    for (int i = 0; i <= size + 3; ++i) {
        ref_tmp[i] = 0;
    }
}