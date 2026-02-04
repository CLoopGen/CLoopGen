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
extern uint16_t freqs[512];
extern int b;
extern int c;
extern int e;
extern int g;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (b = 0 , c = m->size; b < c; b++) {
    int idx = b;
    m->cnts[idx] -= m->cnts[idx] >> 1;
    a = a + m->cnts[idx];
    e = m->symbols[idx];
    g = freqs[2 * e + 1];
    m->freqs[2 * idx] = freqs[2 * e];
    m->freqs[2 * idx + 1] = g;
}
}
