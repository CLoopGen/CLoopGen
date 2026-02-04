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
extern uint16_t cnts[256];
extern int b;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t a;
    int b;
    for (a = 1 << (0 < m->fshift ? m->fshift - 1 : 0), b = 0; b < 256; b += 4) {
        cnts[b] = a;
        if (b + 1 < 256) cnts[b + 1] = a;
        if (b + 2 < 256) cnts[b + 2] = a;
        if (b + 3 < 256) cnts[b + 3] = a;
    }
}
