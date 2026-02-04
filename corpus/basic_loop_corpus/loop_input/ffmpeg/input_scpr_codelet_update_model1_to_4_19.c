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

uint32_t val;
PixelModel3 n;
int i;

void init_vars() {
    val = 42;
    n.type = 0;
    n.length = 255;
    n.maxpos = 0;
    n.fshift = 8;
    n.size = 256;
    n.cntsum = 0;

    for (int j = 0; j < 256; j++) {
        n.symbols[j] = (uint8_t)(j ^ 0x5A);
        n.freqs[j] = 0;
        n.freqs1[j] = (uint16_t)(j * 3);
        n.cnts[j] = (uint16_t)(j % 100);
        if (j < 32) {
            n.dectab[j] = (uint8_t)(j * 2);
        }
    }

    val = n.symbols[128];
}