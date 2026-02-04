#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int size;
int x;
uint16_t *top;
uint16_t *ref_tmp;

void init_vars() {
    size = (1 << 24) / sizeof(uint16_t);  // ~16.7 million elements, ~32MB total for two arrays
    top = aligned_alloc(64, (size + 1) * sizeof(uint16_t));
    ref_tmp = aligned_alloc(64, (size + 4) * sizeof(uint16_t));

    if (!top || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= size + 3; i++) {
        if (i < (int)size + 1) top[i] = (uint16_t)(i & 0xFFFF);
        if (i < (int)size + 4) ref_tmp[i] = 0;
    }
}