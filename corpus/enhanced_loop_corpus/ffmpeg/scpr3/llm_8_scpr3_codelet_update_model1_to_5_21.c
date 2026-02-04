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
    for (i = 0; i < size && i < 256; i += 2) {
        uint32_t match = (val == n.symbols[i]);
        n.freqs[i] = match ? 100 : 50;
        n.cnts[i] = n.freqs[i] * 2;
        if (match) {
            n.maxpos = i;
        }
        if (i + 1 < size) {
            match = (val == n.symbols[i+1]);
            n.freqs[i+1] = match ? 100 : 50;
            n.cnts[i+1] = n.freqs[i+1] * 2;
            if (match) {
                n.maxpos = i+1;
            }
        }
    }
}
