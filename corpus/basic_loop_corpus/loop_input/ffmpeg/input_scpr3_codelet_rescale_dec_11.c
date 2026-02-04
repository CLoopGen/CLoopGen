#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
uint16_t freqs[512];
int b;
int c;
int e;
int g;
uint32_t a;

void init_vars() {
    // Allocate and initialize the PixelModel3 structure
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    // Set size to 256 to match arrays in struct, ensuring loop runs safely
    m->size = 256;

    // Initialize symbols with values in valid range [0, 255]
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i % 256;
        m->cnts[i] = (i * 7) % 1000;  // arbitrary non-zero counts
    }

    // Initialize freqs array used externally
    for (int i = 0; i < 512; i++) {
        freqs[i] = (i * 13) % 32768;  // reasonable frequency values
    }

    // Initialize other scalar variables to zero
    a = 0;
    b = 0;
    c = m->size;
    e = 0;
    g = 0;
}