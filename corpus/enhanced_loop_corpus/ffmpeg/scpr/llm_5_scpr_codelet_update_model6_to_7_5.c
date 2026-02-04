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
for (i = 0; i < length; i++) {
    index = m->symbols[i];
    uint8_t has_count = (uint8_t)(m->cnts[i] != 0);
    freqs[index] = has_count ? m->freqs[2 * i] : 0;
    freqs1[index] = has_count ? m->freqs[2 * i + 1] : 0;
    cnts[index] = has_count ? m->cnts[i] : 0;
}
}
