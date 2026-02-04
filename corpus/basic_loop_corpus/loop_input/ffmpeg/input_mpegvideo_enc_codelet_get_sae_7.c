#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int ref;
int stride;
int x;
int y;
int acc;

void init_vars() {
    stride = 16;
    ref = 128;
    acc = 0;
    x = 0;
    y = 0;

    size_t total_size = 16 * 16;
    src = (uint8_t*)aligned_alloc(32, total_size);
    if (!src) exit(1);

    for (size_t i = 0; i < total_size; i++) {
        src[i] = rand() % 256;
    }
}