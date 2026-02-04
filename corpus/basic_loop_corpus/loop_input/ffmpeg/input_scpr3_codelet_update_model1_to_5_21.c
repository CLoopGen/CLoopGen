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

uint32_t val;
PixelModel3 n;
int i;
int size;

void init_vars() {
    val = 42;
    size = 256;
    i = 0;
    
    n.type = 1;
    n.length = 256;
    n.maxpos = 0;
    n.fshift = 8;
    n.size = 256;
    n.cntsum = 0;
    
    for (int j = 0; j < 256; j++) {
        n.symbols[j] = (j * 17 + 43) % 256;
        n.freqs[j] = 0;
        n.freqs1[j] = (j * 31) % 1000;
        n.cnts[j] = (j * 13) % 500;
    }
    
    for (int j = 0; j < 32; j++) {
        n.dectab[j] = (j * 7) % 256;
    }
}