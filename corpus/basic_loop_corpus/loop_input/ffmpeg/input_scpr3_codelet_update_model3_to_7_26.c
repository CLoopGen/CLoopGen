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

PixelModel3 n;
int c;
int d;

void init_vars() {
    // Initialize struct fields to zero or safe default values
    n.type = 0;
    n.length = 0;
    n.maxpos = 0;
    n.fshift = 0;
    n.size = 0;
    n.cntsum = 0;
    
    for (int i = 0; i < 256; i++) {
        n.symbols[i] = 0;
        n.freqs[i] = 0;
        n.freqs1[i] = 0;
        n.cnts[i] = 0;
    }
    
    for (int i = 0; i < 32; i++) {
        n.dectab[i] = 0;
    }
    
    c = 0;
    d = 0;
}