#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

ptrdiff_t stride;
int i;
int j;
int size;
uint8_t *src;
uint32_t a;

void init_vars() {
    size = 4096; 
    stride = size;
    a = 0xDEADBEEF;
    src = (uint8_t*)aligned_alloc(64, (size_t)stride * (size_t)size);
    if (!src) {
        exit(1);
    }
}