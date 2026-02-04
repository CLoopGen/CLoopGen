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
extern int _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    if (index >= m->size) return;
    for (int c = m->size - 1; c >= index; c--) {
        m->symbols[c + 1] = m->symbols[c];
        if (m->freqs[c] > 0) {
            m->freqs[c + 1] = m->freqs[c] + 1;
        } else {
            m->freqs[c + 1] = 1;
        }
    }
}
