#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct BswapDSPContext {
    void (*bswap_buf)(uint32_t *, const uint32_t *, int);
    void (*bswap16_buf)(uint16_t *, const uint16_t *, int);
} BswapDSPContext;

typedef struct TSContext {
    BswapDSPContext bdsp;
    uint8_t buffer[32] __attribute__((aligned(16)));
    int16_t vector[8];
    int offset1[2];
    int offset2[4];
    int pulseoff[4];
    int pulsepos[4];
    int pulseval[4];
    int flag;
    int filtbuf[146];
    int prevfilt[8];
    int16_t tmp1[8];
    int16_t tmp2[8];
    int16_t tmp3[8];
    int16_t cvector[8];
    int filtval;
    int16_t newvec[60];
    int16_t filters[32];
} TSContext;

int16_t ts_pulse_scales[64];
TSContext *dec;
int quart;
int16_t tmp[7];
int i;
int t;

void init_vars() {
    // Allocate and initialize dec
    dec = (TSContext*)aligned_alloc(16, sizeof(TSContext));
    if (!dec) exit(1);

    // Initialize all fields of dec to avoid undefined behavior
    memset(dec, 0, sizeof(TSContext));

    // Set quart to a valid index: 0 <= quart < 4 for pulseoff/pulseval arrays
    quart = 0;

    // Initialize pulseoff and pulseval so that indexing is safe
    for (int idx = 0; idx < 4; idx++) {
        dec->pulseoff[idx] = idx % 4;  // ensures pulseoff in [0..3]
        dec->pulseval[idx] = 0x3F;     // 6 bits set -> enough for 3 shifts of 2 bits
    }

    // Initialize ts_pulse_scales with non-zero values
    for (int idx = 0; idx < 64; idx++) {
        ts_pulse_scales[idx] = (int16_t)(idx * 100);
    }

    // Zero out tmp array
    for (int idx = 0; idx < 7; idx++) {
        tmp[idx] = 0;
    }

    // Initialize loop counters
    i = 0;
    t = 0;
}