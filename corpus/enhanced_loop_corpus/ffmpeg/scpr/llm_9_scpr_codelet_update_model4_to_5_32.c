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
extern int e;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (; c < m->size; c++, g += step) {
        n.symbols[g] = m->symbols[c];
        n.freqs[g] = m->freqs[c];
        if ((e += m->freqs[c]) > 32768) {
            step = 2;
            e = 0;
        } else {
            step = 1;
        }
    }
}
