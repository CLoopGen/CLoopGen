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
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    m->fshift = 9;  

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = 0;
        m->freqs[i] = 0;
        m->freqs1[i] = 0;
        m->cnts[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = 0;
    }

    m->type = 0;
    m->length = 0;
    m->maxpos = 0;
    m->size = 0;
    m->cntsum = 0;

    for (int i = 0; i < 256; i++) {
        cnts[i] = 0;
    }

    b = 0;
    a = 0;
}