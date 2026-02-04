#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t* clut;
uint8_t list_inv[256];
int count;
int i;

void init_vars() {
    count = 1000000;
    i = 256;
    clut = aligned_alloc(4, 4 * 256);
    for (int j = 0; j < 256; j++) {
        list_inv[j] = j % 256;
    }
    for (int j = 0; j < 256; j++) {
        ((uint32_t*)clut)[j] = 0;
    }
}