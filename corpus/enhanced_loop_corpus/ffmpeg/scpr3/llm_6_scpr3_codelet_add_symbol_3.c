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
    uint8_t temp_sym[256];
    uint16_t temp_freq[256];
    int size = m->size;
    int idx = index;
    for (int c = size - 1; c >= idx; c--) {
        temp_sym[c + 1] = m->symbols[c];
        temp_freq[c + 1] = m->freqs[c];
    }
    for (int c = size - 1; c >= idx; c--) {
        m->symbols[c + 1] = temp_sym[c + 1];
        m->freqs[c + 1] = temp_freq[c + 1];
    }
}
