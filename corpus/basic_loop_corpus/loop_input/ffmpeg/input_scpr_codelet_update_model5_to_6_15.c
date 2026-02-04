#include <stdint.h>
#include <string.h>

typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[512];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

PixelModel3 n;
int c;
int e;
int f;
int g;
int k;
int q;

void init_vars() {
    n.type = 1;
    n.length = 1;
    n.maxpos = 255;
    n.fshift = 4;
    n.size = 256;
    n.cntsum = 0;

    for (int i = 0; i < 256; i++) {
        n.symbols[i] = (uint8_t)(255 - i);
        n.freqs1[i] = (uint16_t)(i * 3);
        n.cnts[i] = (uint16_t)(i % 100);
        n.dectab[i] = (uint8_t)(i * 2);
    }

    for (int i = 0; i < 512; i++) {
        n.freqs[i] = (uint16_t)((i * 7) % 1000);
    }

    c = 0;
    e = 0;
    f = 0;
    g = 0;
    k = 0;
    q = 0;
}