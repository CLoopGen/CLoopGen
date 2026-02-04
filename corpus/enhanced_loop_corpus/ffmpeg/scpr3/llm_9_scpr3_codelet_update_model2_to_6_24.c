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
extern uint8_t value;
extern PixelModel3 n;
extern int c;
extern int d;
extern int e;
extern int f;
extern int g;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (f = d = 0; f < c && f < 128; f++) {
    int p = f << 1;
    int k = m->symbols[f];
    int l;
    g += (k - q);
    if (k == value) {
        d = f;
        q = 128;
    } else {
        q = 64;
    }
    l = q << e;
    n.freqs[p] = l;
    n.freqs[p + 1] = g << e;
    n.symbols[f] = k;
    n.cnts[f] = l >> 1;
    g += q;
    q = k + 1;
}
}
