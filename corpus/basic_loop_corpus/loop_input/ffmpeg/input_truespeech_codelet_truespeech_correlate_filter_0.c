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

int16_t ts_decay_994_1000[8];
TSContext *dec;
int i;

void init_vars() {
    // Allocate and initialize dec
    dec = (TSContext*)aligned_alloc(16, sizeof(TSContext));
    if (!dec) exit(1);

    // Initialize ts_decay_994_1000 with values close to 994/1000 of 32768 (for Q15 fixed point)
    for (int idx = 0; idx < 8; idx++) {
        ts_decay_994_1000[idx] = (int16_t)((994LL * 32768LL) / 1000LL); // ~32571
    }

    // Initialize cvector with non-zero values to make multiplication observable
    for (int idx = 0; idx < 8; idx++) {
        dec->cvector[idx] = (idx + 1) * 1000;
    }

    // Zero out other fields to ensure defined behavior
    memset(&dec->bdsp, 0, sizeof(dec->bdsp));
    memset(dec->buffer, 0, sizeof(dec->buffer));
    memset(dec->vector, 0, sizeof(dec->vector));
    memset(dec->offset1, 0, sizeof(dec->offset1));
    memset(dec->offset2, 0, sizeof(dec->offset2));
    memset(dec->pulseoff, 0, sizeof(dec->pulseoff));
    memset(dec->pulsepos, 0, sizeof(dec->pulsepos));
    memset(dec->pulseval, 0, sizeof(dec->pulseval));
    dec->flag = 0;
    memset(dec->filtbuf, 0, sizeof(dec->filtbuf));
    memset(dec->prevfilt, 0, sizeof(dec->prevfilt));
    memset(dec->tmp1, 0, sizeof(dec->tmp1));
    memset(dec->tmp2, 0, sizeof(dec->tmp2));
    memset(dec->tmp3, 0, sizeof(dec->tmp3));
    dec->filtval = 0;
    memset(dec->newvec, 0, sizeof(dec->newvec));
    memset(dec->filters, 0, sizeof(dec->filters));
}