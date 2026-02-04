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

PixelModel3 *m;
uint8_t value;
PixelModel3 n;
int c;
int d;
int e;
int f;
int g;
int q;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    
    // Set up problem size: choose c such that loop runs ~0.01 seconds
    // Based on typical performance, c around 100,000 - 200,000 should be sufficient
    c = 131072;  // 128K iterations - reasonable for ~0.01 sec
    
    // Ensure c does not exceed symbol array bounds in the structure
    if (c > 256) {
        c = 256;  // Cap at maximum safe size given arrays of size 256
    }
    
    // Initialize other scalar variables
    value = 42;
    e = 2;
    g = 1;
    q = 100;
    
    // Initialize m's symbols array to valid values within bounds
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i * 71 % 256);  // pseudo-random pattern
    }
    
    // Initialize n structure
    n.type = 1;
    n.length = 1;
    n.maxpos = 1;
    n.fshift = 1;
    n.size = 1;
    n.cntsum = 1;
    
    // Zero out arrays in n
    for (int i = 0; i < 256; i++) {
        n.freqs[i] = 0;
        n.freqs1[i] = 0;
        n.cnts[i] = 0;
        n.symbols[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        n.dectab[i] = 0;
    }
    
    // Initialize loop counters
    d = 0;
    f = 0;
}