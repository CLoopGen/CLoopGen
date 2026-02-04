#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

ptrdiff_t stride;
int i;
int j;
int size;
uint16_t *src;
uint64_t a;

void init_vars() {
    size = 1024;
    stride = 2048;
    a = 0xdeadbeefdeadbeefULL;

    src = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * stride * size);
    if (!src) {
        exit(1);
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}