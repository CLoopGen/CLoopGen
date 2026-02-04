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
extern int length;
extern int i;
extern int _usr_index;
extern uint16_t *freqs;
extern uint16_t *freqs1;
extern uint16_t *cnts;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Reduced computational intensity with simplified access and early exit
    int i = 0;
    uint8_t *symbols = m->symbols;
    uint16_t *src_freqs = m->freqs;
    uint16_t *src_cnts = m->cnts;
    uint16_t *dst_freqs = freqs;
    uint16_t *dst_freqs1 = freqs1;
    uint16_t *dst_cnts = cnts;

    // Reduce trip count by processing only up to min(length, 128) to lower intensity
    int effective_length = length > 128 ? 128 : length;

    for (; i < effective_length; i++) {
        if (src_cnts[i]) {
            index = symbols[i];
            dst_freqs[index] = src_freqs[2 * i];
            dst_freqs1[index] = src_freqs[2 * i + 1];
            dst_cnts[index] = src_cnts[i];
        }
    }
}
