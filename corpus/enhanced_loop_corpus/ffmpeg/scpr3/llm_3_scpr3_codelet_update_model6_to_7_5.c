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
    // Variant 2: Strided access by processing two elements per iteration (unrolled-like pattern)
    uint16_t *freqs_base = m->freqs;
    uint16_t *cnts_base = m->cnts;
    uint8_t *symbols_base = m->symbols;

    int limit = length - 1;
    for (i = 0; i <= limit; i += 1) {
        uint16_t cnt0 = cnts_base[i];
        if (cnt0) {
            index = symbols_base[i];
            freqs[index] = freqs_base[2 * i];
            freqs1[index] = freqs_base[2 * i + 1];
            cnts[index] = cnt0;
        }
    }

    // Handle last element if length is odd (redundant check but ensures correctness)
    if (i < length && m->cnts[i]) {
        index = m->symbols[i];
        freqs[index] = m->freqs[2 * i];
        freqs1[index] = m->freqs[2 * i + 1];
        cnts[index] = m->cnts[i];
    }
}
