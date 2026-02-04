#include <stdlib.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int bpp;
int i;
int p;

void init_vars() {
    bpp = 1 << 20; // Approximately 1MB of data

    src = (uint8_t *)malloc(bpp * sizeof(uint8_t));
    dst = (uint8_t *)malloc(bpp * sizeof(uint8_t));
    last = (uint8_t *)malloc(bpp * sizeof(uint8_t));

    for (i = 0; i < bpp; i++) {
        src[i] = rand() & 0xFF;
        last[i] = rand() & 0xFF;
        dst[i] = 0;
    }
}