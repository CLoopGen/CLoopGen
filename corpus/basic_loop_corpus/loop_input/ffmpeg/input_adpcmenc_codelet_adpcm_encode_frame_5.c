#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 67108864; // 64M elements, ~0.01 sec on modern CPU
int i;
uint8_t *dst;
uint8_t *buf;

void init_vars() {
    buf = aligned_alloc(32, sizeof(uint8_t) * n * 2);
    dst = aligned_alloc(32, sizeof(uint8_t) * n);
    for (int j = 0; j < n * 2; j++) {
        buf[j] = (uint8_t)(j & 0xFF);
    }
}