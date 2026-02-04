#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int start_x;
uint8_t *bufp;

void init_vars() {
    start_x = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    bufp = (uint8_t*)aligned_alloc(32, start_x + 1);
    if (!bufp) {
        exit(1);
    }
    for (int i = 0; i <= start_x; i++) {
        bufp[i] = (uint8_t)(i & 0xFF);
    }
}