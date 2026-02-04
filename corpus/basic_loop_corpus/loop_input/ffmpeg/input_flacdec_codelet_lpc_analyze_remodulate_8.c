#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *decoded;
int coeffs[32];
int order = 16;
int qlevel = 4;
int len = 1 << 20;
int i;
int j;

void init_vars() {
    decoded = aligned_alloc(32, sizeof(uint32_t) * (len + order));
    for (int idx = 0; idx < len + order; idx++) {
        decoded[idx] = rand() % 256;
    }
    for (int idx = 0; idx < 32; idx++) {
        coeffs[idx] = rand() % 17 - 8;
    }
    order = 16;
    qlevel = 4;
    len = 1 << 20;
}