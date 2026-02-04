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

extern uint32_t val;
extern PixelModel3 n;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (size > 128) ? 1 : 2;
    for (i = 0; i < size; i += step) {
        uint8_t sym = n.symbols[i];
        uint16_t base_freq = (val == sym) ? 100 : 50;
        n.freqs[i] = base_freq;
        n.freqs1[i] = base_freq + 10;
        if (val == sym) {
            n.maxpos = i;
            n.cntsum += n.freqs[i];
        }
    }
}
