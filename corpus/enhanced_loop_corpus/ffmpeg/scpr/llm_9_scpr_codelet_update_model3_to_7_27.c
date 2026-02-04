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

extern PixelModel3 *m;
extern PixelModel3 n;
extern int c;
extern int d;
extern int e;
extern int g;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (m->size > 128) ? 4 : (m->size > 32) ? 2 : 1;
    for (c = m->size, d = (4096 - (256 - c)) / (c + 1) | 0, e = d - (d >> 1), g = 0; g < c; g += stride) {
        for (int h = 0; h < stride && (g + h) < c; ++h) {
            q = m->symbols[g + h];
            n.freqs[q] = d;
            n.cnts[q] = e;
        }
    }
}
