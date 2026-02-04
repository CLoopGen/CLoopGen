#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int start_x;
uint16_t *bufp;

void init_vars() {
    start_x = 131072; // Size to achieve ~0.01 sec runtime: 131072 elements * 2 bytes = ~256 KB
    bufp = (uint16_t*)aligned_alloc(_Alignof(uint16_t), sizeof(uint16_t) * (start_x + 1));
    if (!bufp) {
        exit(1);
    }
    for (int i = 0; i <= start_x; i++) {
        bufp[i] = (uint16_t)(i & 0xFFFF);
    }
}