#include <stdlib.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int bpp;
int i;

void init_vars() {
    bpp = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    src = (uint8_t*)malloc(bpp * sizeof(uint8_t));
    dst = (uint8_t*)malloc(bpp * sizeof(uint8_t));

    for (int j = 0; j < bpp; j++) {
        src[j] = j & 0xFF;
    }
}