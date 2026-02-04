#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

uint8_t value = 200;
PixelModel3 n;
int c = 256;
int d = 50;
int f;
int g;
int k;
int p;

void init_vars() {
    n.type = 1;
    n.length = 255;
    n.maxpos = 128;
    n.fshift = 4;
    n.size = 256;
    n.cntsum = 0;

    for (int i = 0; i < 256; i++) {
        n.symbols[i] = rand() % 256;
        n.freqs1[i] = rand() % 1000;
        n.cnts[i] = rand() % 500;
        n.dectab[i % 32] = i * 7;
    }

    for (int i = 0; i < 512; i++) {
        n.freqs[i] = rand() % 1000;
    }
}

__attribute__((constructor))
static void constructor_init() {
    srand(time(NULL));
    init_vars();
}