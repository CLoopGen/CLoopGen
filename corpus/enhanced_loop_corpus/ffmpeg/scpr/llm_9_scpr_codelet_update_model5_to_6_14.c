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
extern int k;
extern int q;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (q = d = 0, g = 0; g < c; g += 2) {
        if (g + 1 < c) {
            int p1 = m->symbols[g];
            int p2 = m->symbols[g + 1];
            d = d + (p1 - q);
            int q1 = m->freqs[g];
            int q2 = m->freqs[g + 1];
            k = q1 << e;
            int k2 = q2 << e;
            n.freqs[2 * g] = k;
            n.freqs[2 * g + 1] = d << e;
            n.freqs[2 * (g + 1)] = k2;
            n.freqs[2 * (g + 1) + 1] = (d + (p2 - p1)) << e;
            n.cnts[g] = k - (k >> 1);
            n.cnts[g + 1] = k2 - (k2 >> 1);
            n.symbols[g] = p1;
            n.symbols[g + 1] = p2;
            d += q1 + q2;
            q = p2 + 1;
        } else {
            p = m->symbols[g];
            d = d + (p - q);
            q = m->freqs[g];
            k = q << e;
            n.freqs[2 * g] = k;
            n.freqs[2 * g + 1] = d << e;
            n.cnts[g] = k - (k >> 1);
            n.symbols[g] = p;
            d += q;
            q = p + 1;
        }
    }
}
