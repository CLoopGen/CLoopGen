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
    uint16_t freqs[512];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

PixelModel3 *m;
int length;
int i;
int _usr_index;
uint16_t *freqs;
uint16_t *freqs1;
uint16_t *cnts;

#define index _usr_index

void init_vars() {
    const int data_size = 1 << 20; // ~1MB of working data, adjust as needed for timing

    // Allocate and initialize m
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    // Set length to 256 since arrays in PixelModel3 are fixed size [256]
    length = 256;
    m->length = 256;

    // Initialize symbols and cnts: map each active symbol to a unique index, skip some entries randomly
    for (int i = 0; i < length; i++) {
        m->symbols[i] = (uint8_t)i;
        m->cnts[i] = (i % 7 != 0) ? (uint16_t)(i * 3 + 1) : 0; // Zero out every 7th entry to test condition
    }

    // Initialize freqs: needs 2*i and 2*i+1 access, so must have at least 512 elements
    for (int i = 0; i < 512; i++) {
        m->freqs[i] = (uint16_t)(i * 2 + 1);
    }

    // Allocate output arrays: freqs, freqs1, cnts (each 256 elements)
    freqs = (uint16_t*)calloc(256, sizeof(uint16_t));
    freqs1 = (uint16_t*)calloc(256, sizeof(uint16_t));
    cnts = (uint16_t*)calloc(256, sizeof(uint16_t));

    if (!freqs || !freqs1 || !cnts) exit(1);
}