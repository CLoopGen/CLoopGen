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
uint32_t a;

void init_vars() {
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    m->type = 1;
    m->length = 255;
    m->maxpos = 128;
    m->fshift = 4;

    // Set size to ~65k to make loop take around 0.01s considering cheap operations
    // Each iteration: shift and add, very fast. Need enough iterations for measurable time.
    // Modern CPU can do billions of ops/sec, so aim for ~10M operations for 0.01s
    // Using 65536 gives 65536 iterations, which is reasonable
    m->size = 65536;

    m->cntsum = 0;

    // Initialize symbols, freqs, freqs1, cnts, dectab
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i & 0xFF;
        m->freqs[i] = (i * 17 + 100) & 0xFFFF;  // deterministic non-zero
        m->freqs1[i] = (i * 31 + 50) & 0xFFFF;
        m->cnts[i] = (i * 7 + 200) & 0xFFFF;
    }

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (i * 5 + 10) & 0xFF;
    }

    // For indices >= 256, we need to ensure that freqs array access up to m->size-1 is valid
    // But m->freqs only has 256 elements! So we must cap m->size at 256 to prevent OOB access
    // Correction: the loop accesses m->freqs[b] with b from 0 to m->size-1
    // Since m->freqs has only 256 entries, m->size must be <= 256

    // Therefore, correct m->size to 256 to avoid out-of-bounds access
    m->size = 256;

    // Recompute initialization accordingly
    for (int i = 0; i < 256; i++) {
        m->freqs[i] = (i * 17 + 100) & 0xFFFF;
    }

    a = 0;
}