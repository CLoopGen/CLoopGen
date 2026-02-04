#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
uint8_t *block;
int x;
int y;
int mn;
int mx;

void init_vars() {
    stride = 64;
    block = (uint8_t*)aligned_alloc(32, 1 << 20);
    for (size_t i = 0; i < (1 << 20); i++) {
        block[i] = rand() % 256;
    }
    mn = 255;
    mx = 0;
}