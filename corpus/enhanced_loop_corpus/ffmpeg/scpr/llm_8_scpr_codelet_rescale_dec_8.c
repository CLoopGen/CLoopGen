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
    uint32_t shift_val = (0 < m->fshift ? m->fshift : 1);
    a = 1 << (shift_val > 8 ? 8 : shift_val - 1);
    for (b = 0; b < 256; b += 4) {
        cnts[b]     = a + b;
        cnts[b + 1] = a + b + 1;
        cnts[b + 2] = a + b + 2;
        cnts[b + 3] = a + b + 3;
    }
}
