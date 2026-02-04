#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

PixelModel3 *m;
PixelModel3 n;
int i;

void init_vars() {
    n.size = 256;

    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) {
        exit(1);
    }

    for (int idx = 0; idx < 256; idx++) {
        m->symbols[idx] = (uint8_t)(idx * idx + 7);
    }
}