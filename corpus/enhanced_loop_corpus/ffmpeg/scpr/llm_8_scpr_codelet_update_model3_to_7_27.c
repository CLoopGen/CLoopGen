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
    for (c = m->size, d = (8192 - (512 - c)) / (c + 3) | 0, e = d - (d >> 2), g = 0; g < c; g += 2) {
        q = g;
        if (q < c) {
            q = m->symbols[q];
            n.freqs[q] = d + (d >> 1);
            n.cnts[q] = e;
        }
        q = g + 1;
        if (q < c) {
            q = m->symbols[q];
            n.freqs[q] = d - (d >> 3);
            n.cnts[q] = e - (e >> 2);
        }
    }
}
