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
int b;

void init_vars() {
    b = 256;
    
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) {
        exit(1);
    }
    
    for (int idx = 0; idx < 256; idx++) {
        m->symbols[idx] = (uint8_t)(idx * idx + 17);
        m->freqs[idx] = (uint16_t)(idx + 42);
        m->freqs1[idx] = (uint16_t)(idx + 100);
        m->cnts[idx] = (uint16_t)(idx + 200);
    }
    
    for (int idx = 0; idx < 32; idx++) {
        m->dectab[idx] = (uint8_t)(idx * 3 + 1);
    }
    
    m->type = 1;
    m->length = 255;
    m->maxpos = 200;
    m->fshift = 5;
    m->size = 1024;
    m->cntsum = 50000;
    
    for (int idx = 0; idx < 256; idx++) {
        n.symbols[idx] = 0;
    }
}