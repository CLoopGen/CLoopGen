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
    const size_t data_size = 64 << 20; // 64 MB of data
    size = (data_size / sizeof(uint16_t)) - 1; // Ensure top[x-1] is valid for x=0 to size (step 4)

    top = (uint16_t*)aligned_alloc(8, (size + 2) * sizeof(uint16_t));
    ref_tmp = (uint16_t*)aligned_alloc(8, (size + 4) * sizeof(uint16_t));

    if (!top || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= size + 1; i++) {
        top[i] = i & 0xFFFF;
    }
    for (int i = 0; i <= size + 3; i++) {
        ref_tmp[i] = 0;
    }
}