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
int _usr_index;

#define index _usr_index

void init_vars() {
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    m->size = 200;  // Ensure c+1 <= 255 in loop, so c starts at 199 and goes down to index
    index = 100;    // Set index such that we process about 100 elements

    // Initialize symbols and freqs arrays with dummy data
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i & 0xFF);
        m->freqs[i] = (uint16_t)((i * 7) & 0xFFFF);
        m->freqs1[i] = (uint16_t)((i * 13) & 0xFFFF);
        m->cnts[i] = (uint16_t)((i * 17) & 0xFFFF);
    }

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (uint8_t)((i * 5) & 0xFF);
    }

    // Other fields initialization
    m->type = 1;
    m->length = 2;
    m->maxpos = 3;
    m->fshift = 4;
    m->cntsum = 1000;
}