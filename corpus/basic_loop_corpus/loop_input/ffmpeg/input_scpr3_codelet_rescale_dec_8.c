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
uint16_t cnts[256];
int b;
uint32_t a;

void init_vars() {
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    m->fshift = 5;
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i % 256;
        m->freqs[i] = i % 100;
        m->freqs1[i] = i % 90;
        m->cnts[i] = i % 80;
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = i % 16;
    }
    m->type = 1;
    m->length = 255;
    m->maxpos = 128;
    m->size = 1024;
    m->cntsum = 100000;
}