#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *bits;
uint32_t exit_at_level[33];
unsigned int i;
unsigned int p;

void init_vars() {
    bits = (uint8_t*)malloc(1024 * 1024); // 1MB data size
    if (!bits) {
        exit(1);
    }
    p = 524288; // choose p such that bits[p] is valid
    bits[p] = 32; // ensure loop runs for 32 iterations: i from 0 to 31
}

__attribute__((destructor))
static void cleanup() {
    free(bits);
}