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
    n.type = 0;
    n.length = 1;
    n.maxpos = 255;
    n.fshift = 4;
    n.size = 256;
    n.cntsum = 0;

    for (int i = 0; i < 256; i++) {
        n.symbols[i] = (uint8_t)(255 - i);
        n.freqs[2 * i] = (uint16_t)(100 + (i * 37 % 199));
        n.freqs[2 * i + 1] = (uint16_t)(i * 53 % 101);
        n.freqs1[i] = (uint16_t)(i * 97 % 211);
        n.cnts[i] = (uint16_t)(255 - i);
    }

    for (int i = 0; i < 32; i++) {
        n.dectab[i] = (uint8_t)(i * 7 % 251);
    }
}