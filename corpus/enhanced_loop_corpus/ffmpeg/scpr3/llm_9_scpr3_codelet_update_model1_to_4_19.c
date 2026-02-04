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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *freqs = n.freqs;
    uint8_t *symbols = n.symbols;
    uint32_t size = n.size;
    uint8_t found = 0;

    for (i = 0; i < size && i < 256; i += 2) {
        uint8_t eq0 = (val == symbols[i]);
        freqs[i] = eq0 ? 100 : 50;
        if (eq0) {
            n.maxpos = i;
            found = 1;
        }
        if (i + 1 < size) {
            uint8_t eq1 = (val == symbols[i+1]);
            freqs[i+1] = eq1 ? 100 : 50;
            if (eq1) {
                n.maxpos = i + 1;
                found = 1;
            }
        }
    }

    if (!found && n.size > 0) {
        n.maxpos = 0;
    }
}
