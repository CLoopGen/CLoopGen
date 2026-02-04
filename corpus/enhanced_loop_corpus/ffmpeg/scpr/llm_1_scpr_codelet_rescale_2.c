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
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (m->size > 0) {
        for (int b = 0; b < m->size; b += 2) {
            m->freqs[b] -= m->freqs[b] >> 1;
            a += m->freqs[b];
            if (b + 1 < m->size) {
                m->freqs[b + 1] -= m->freqs[b + 1] >> 1;
                a += m->freqs[b + 1];
            }
        }
    }
}
