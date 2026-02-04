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
    size = (1 << 20); // 1MB of data: 2^20 elements of uint16_t = 2^19 * 8 bytes accessed via 64-bit loads/stores
    left = aligned_alloc(64, (size + 1) * sizeof(uint16_t));
    ref_tmp = aligned_alloc(64, size * sizeof(uint16_t));

    if (!left || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= size; ++i) {
        left[i] = i & 0xFFFF;
    }
    for (int i = 0; i < size; ++i) {
        ref_tmp[i] = 0;
    }
}