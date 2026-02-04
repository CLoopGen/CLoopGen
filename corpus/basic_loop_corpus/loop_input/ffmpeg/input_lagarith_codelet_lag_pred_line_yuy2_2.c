#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int L;
int HEAD;
int i;

void init_vars() {
    HEAD = 1 << 20; // 1 million elements for ~0.01 sec runtime
    buf = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * HEAD);
    if (!buf) {
        exit(1);
    }
    for (int j = 0; j < HEAD; j++) {
        buf[j] = (uint8_t)(j & 0xFF);
    }
    L = 0;
}