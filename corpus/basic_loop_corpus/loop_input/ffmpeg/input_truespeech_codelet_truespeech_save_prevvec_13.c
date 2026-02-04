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

TSContext *c;
int i;

void init_vars() {
    c = malloc(sizeof(TSContext));
    if (!c) exit(1);

    c->bdsp.bswap_buf = NULL;
    c->bdsp.bswap16_buf = NULL;

    for (int j = 0; j < 32; j++)
        c->buffer[j] = j;

    for (int j = 0; j < 8; j++) {
        c->vector[j] = j;
        c->cvector[j] = j + 10;
    }

    for (int j = 0; j < 2; j++)
        c->offset1[j] = j;

    for (int j = 0; j < 4; j++) {
        c->offset2[j] = j;
        c->pulseoff[j] = j;
        c->pulsepos[j] = j;
        c->pulseval[j] = j * 10;
    }

    c->flag = 1;
    for (int j = 0; j < 146; j++)
        c->filtbuf[j] = j * 2;

    for (int j = 0; j < 8; j++)
        c->prevfilt[j] = 0;

    for (int j = 0; j < 8; j++) {
        c->tmp1[j] = j;
        c->tmp2[j] = j + 1;
        c->tmp3[j] = j + 2;
    }

    c->filtval = 42;
    for (int j = 0; j < 60; j++)
        c->newvec[j] = j * 3;

    for (int j = 0; j < 32; j++)
        c->filters[j] = j * 5;
}