#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x, y;
ptrdiff_t srcstride = 64;

int16_t *dst;
uint8_t *src;
int8_t *filter;

void init_vars() {
    dst = aligned_alloc(64, sizeof(int16_t) * 64 * 64);
    src = aligned_alloc(64, sizeof(uint8_t) * (64 + 7) * (64 + 7));
    filter = malloc(sizeof(int8_t) * 8);

    uint8_t *src_base = src;
    src += 3 * 64 + 3;

    for (int i = 0; i < (64 + 7); i++) {
        for (int j = 0; j < (64 + 7); j++) {
            src_base[i * (64 + 7) + j] = rand() & 0xFF;
        }
    }

    for (int i = 0; i < 8; i++) {
        filter[i] = rand() & 0xFF - 128;
    }

    for (int i = 0; i < 64 * 64; i++) {
        dst[i] = 0;
    }
}