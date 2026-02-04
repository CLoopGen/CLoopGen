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
uint16_t freqs[512];
int b;
int c;
int e;
int g;
uint32_t a;

void init_vars() {
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    m->size = 256;  

    for (int i = 0; i < 256; i++) {
        m->cnts[i] = (uint16_t)(i * 7 + 100);  
        m->symbols[i] = (uint8_t)(i % 256);
    }

    for (int i = 0; i < 512; i++) {
        freqs[i] = (uint16_t)(i * 3 + 50);
    }

    a = 0;
    b = 0;
    c = 0;
    e = 0;
    g = 0;
}