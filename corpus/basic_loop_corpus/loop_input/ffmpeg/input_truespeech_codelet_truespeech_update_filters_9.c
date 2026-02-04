#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

TSContext *dec;
int16_t *out;
int i;

void init_vars() {
    dec = (TSContext *)aligned_alloc(16, sizeof(TSContext));
    out = (int16_t *)malloc(60 * sizeof(int16_t));

    for (int j = 0; j < 60; j++) {
        dec->newvec[j] = (int16_t)(j % 500);
        out[j] = (int16_t)(j % 400);
    }

    for (int j = 0; j < 146; j++) {
        dec->filtbuf[j] = 0;
    }

    for (int j = 0; j < 8; j++) {
        dec->vector[j] = 0;
        dec->prevfilt[j] = 0;
        dec->tmp1[j] = 0;
        dec->tmp2[j] = 0;
        dec->tmp3[j] = 0;
        dec->cvector[j] = 0;
    }

    for (int j = 0; j < 2; j++) {
        dec->offset1[j] = 0;
    }

    for (int j = 0; j < 4; j++) {
        dec->offset2[j] = 0;
        dec->pulseoff[j] = 0;
        dec->pulsepos[j] = 0;
        dec->pulseval[j] = 0;
    }

    dec->flag = 0;
    dec->filtval = 0;

    for (int j = 0; j < 32; j++) {
        dec->filters[j] = 0;
    }

    for (int j = 0; j < 32; j++) {
        dec->buffer[j] = 0;
    }

    dec->bdsp.bswap_buf = NULL;
    dec->bdsp.bswap16_buf = NULL;
}