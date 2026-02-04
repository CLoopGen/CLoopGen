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
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    top = (uint8_t*)aligned_alloc(32, size + 1);
    ref_tmp = (uint8_t*)aligned_alloc(32, size + 4);

    if (!top || !ref_tmp) {
        exit(1);
    }

    for (int i = 0; i <= size; i++) {
        top[i] = (uint8_t)(i & 0xFF);
    }
    for (int i = 0; i <= size + 3; i++) {
        ref_tmp[i] = 0;
    }
}