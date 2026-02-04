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
int c;
int d;
int e;
int g;
int k;
int q;
int p;

void init_vars() {
    const int data_size = 256; 
    c = data_size;
    e = 4; 

    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i % 128;
        m->freqs[i] = (i * 7) % 1000;
    }

    d = 0;
    g = 0;
    q = 0;
    p = 0;
    k = 0;
}