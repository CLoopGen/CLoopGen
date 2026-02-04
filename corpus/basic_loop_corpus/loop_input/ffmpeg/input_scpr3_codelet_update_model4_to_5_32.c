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
int c;
int e;
int g;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data for ~0.01 sec runtime estimate

    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    m->size = (uint16_t)(data_size % 256 == 0 ? 256 : data_size % 256);
    c = 0;
    g = 0;
    e = 0;

    for (int i = 0; i < 256; ++i) {
        m->symbols[i] = (uint8_t)(i % 256);
        m->freqs[i] = (uint16_t)(i % 100 + 1);
    }

    for (int i = 0; i < 256; ++i) {
        n.symbols[i] = 0;
        n.freqs[i] = 0;
    }
}