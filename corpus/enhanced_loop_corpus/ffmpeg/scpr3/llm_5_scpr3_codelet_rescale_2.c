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
    uint32_t local_a = a;
    for (int b = 0; b < m->size; ++b) {
        uint16_t old_freq = m->freqs[b];
        uint16_t new_freq = old_freq - (old_freq >> 1);
        m->freqs[b] = new_freq;
        if (new_freq >= 8) {
            local_a += new_freq;
        } else if (new_freq >= 4) {
            local_a += new_freq / 2;
        }
    }
    a = local_a;
}
