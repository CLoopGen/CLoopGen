#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *decoded;
int coeffs[32];
int order = 16;
int qlevel = 8;
int len = 1048576;
int i;
int j;

void init_vars() {
    decoded = (uint32_t*)aligned_alloc(32, sizeof(uint32_t) * len);
    for (int idx = 0; idx < len; idx++) {
        decoded[idx] = rand() % 1024;
    }
    for (int idx = 0; idx < 32; idx++) {
        coeffs[idx] = rand() % 64;
    }
}