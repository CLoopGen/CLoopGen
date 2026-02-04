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
int16_t *ptr0;
int16_t *ptr1;
int16_t *filter;
int i;
int t;

#define DATA_SIZE (1 << 20)

static int16_t internal_ptr0[DATA_SIZE];
static int16_t internal_ptr1[DATA_SIZE];
static int16_t internal_filter[32];

void init_vars() {
    dec = (TSContext *)aligned_alloc(16, sizeof(TSContext));
    if (!dec) exit(1);

    ptr0 = internal_ptr0;
    ptr1 = internal_ptr1;
    filter = internal_filter;

    for (int j = 0; j < DATA_SIZE; j++) {
        ptr0[j] = (int16_t)(j & 0x1FF);
    }
    for (int j = 0; j < 32; j++) {
        filter[j] = (int16_t)((j + 1) * 50);
    }

    dec->filtval = 0;
    for (int j = 0; j < 8; j++) {
        dec->vector[j] = (int16_t)(j * 10);
        dec->tmp1[j] = 0;
        dec->tmp2[j] = 0;
        dec->tmp3[j] = 0;
        dec->cvector[j] = (int16_t)(j * 5);
        dec->prevfilt[j] = j * 100;
    }
    for (int j = 0; j < 146; j++) {
        dec->filtbuf[j] = j * 10;
    }
    for (int j = 0; j < 60; j++) {
        dec->newvec[j] = 0;
    }
    for (int j = 0; j < 32; j++) {
        dec->filters[j] = (int16_t)((j + 1) * 30);
    }
    dec->offset1[0] = 0; dec->offset1[1] = 4;
    dec->offset2[0] = 0; dec->offset2[1] = 2; dec->offset2[2] = 4; dec->offset2[3] = 6;
    dec->pulseoff[0] = 1; dec->pulseoff[1] = 2; dec->pulseoff[2] = 3; dec->pulseoff[3] = 4;
    dec->pulsepos[0] = 0; dec->pulsepos[1] = 1; dec->pulsepos[2] = 2; dec->pulsepos[3] = 3;
    dec->pulseval[0] = 100; dec->pulseval[1] = 200; dec->pulseval[2] = 300; dec->pulseval[3] = 400;
    dec->flag = 1;

    for (int j = 0; j < 32; j++) {
        dec->buffer[j] = (uint8_t)(j & 0xFF);
    }

    dec->bdsp.bswap_buf = NULL;
    dec->bdsp.bswap16_buf = NULL;
}