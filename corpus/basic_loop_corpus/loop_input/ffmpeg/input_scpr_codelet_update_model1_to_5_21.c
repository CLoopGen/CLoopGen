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

uint32_t val = 42;
PixelModel3 n;
int i;
int size = 256;

void init_vars() {
    n.type = 1;
    n.length = 256;
    n.maxpos = 0;
    n.fshift = 8;
    n.size = 256;
    n.cntsum = 0;

    for (int j = 0; j < 256; j++) {
        n.symbols[j] = (uint8_t)(j * 73 % 256);
        n.freqs[j] = 0;
        n.freqs1[j] = (uint16_t)(j * 5);
        n.cnts[j] = (uint16_t)(j * 2);
        if (j < 32) {
            n.dectab[j] = (uint8_t)(j * 3);
        }
    }

    val = n.symbols[128];
    size = 256;
    i = 0;
}