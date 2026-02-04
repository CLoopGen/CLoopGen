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
    a = (m->fshift > 0) ? (1U << (m->fshift - 1)) + 5 : 1;
    for (b = 0; b < 256; b++) {
        uint32_t temp = a * (b & 15);
        cnts[b] = (temp >> 4) + (temp & 0xFF);
    }
}
