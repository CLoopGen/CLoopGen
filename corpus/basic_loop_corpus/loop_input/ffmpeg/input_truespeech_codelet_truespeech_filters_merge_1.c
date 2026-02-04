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
int i;

void init_vars() {
    dec = malloc(sizeof(TSContext));
    if (!dec) exit(1);

    for (int j = 0; j < 8; j++) {
        dec->cvector[j] = (int16_t)(j * 5 + 1);
    }

    for (int j = 0; j < 32; j++) {
        dec->filters[j] = 0;
    }

    dec->bdsp.bswap_buf = NULL;
    dec->bdsp.bswap16_buf = NULL;
    for (int j = 0; j < 32; j++) {
        dec->buffer[j] = j % 256;
    }
    for (int j = 0; j < 8; j++) {
        dec->vector[j] = (int16_t)(j * 2);
        dec->tmp1[j] = (int16_t)(j * 3);
        dec->tmp2[j] = (int16_t)(j * 4);
        dec->tmp3[j] = (int16_t)(j * 5);
    }
    for (int j = 0; j < 2; j++) {
        dec->offset1[j] = j * 10;
    }
    for (int j = 0; j < 4; j++) {
        dec->offset2[j] = j * 20;
        dec->pulseoff[j] = j * 5;
        dec->pulsepos[j] = j * 7;
        dec->pulseval[j] = j * 9;
    }
    dec->flag = 1;
    for (int j = 0; j < 146; j++) {
        dec->filtbuf[j] = j * 2;
    }
    for (int j = 0; j < 8; j++) {
        dec->prevfilt[j] = j * 11;
    }
    dec->filtval = 42;
    for (int j = 0; j < 60; j++) {
        dec->newvec[j] = (int16_t)(j * 3);
    }
}