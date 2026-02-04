#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

unsigned char *pd;
int i;
int l;
uint16_t run_val;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    pd = (unsigned char *)aligned_alloc(2, data_size);
    if (!pd) {
        exit(1);
    }
    l = data_size / 2;
    run_val = 0xABCD;
}