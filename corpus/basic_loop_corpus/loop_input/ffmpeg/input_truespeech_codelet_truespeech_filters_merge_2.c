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
    dec = (TSContext*)aligned_alloc(16, sizeof(TSContext));
    
    // Initialize function pointers to NULL
    dec->bdsp.bswap_buf = NULL;
    dec->bdsp.bswap16_buf = NULL;
    
    // Initialize arrays with sample data to avoid undefined behavior
    for (int j = 0; j < 32; j++) {
        dec->buffer[j] = j % 256;
    }
    
    for (int j = 0; j < 8; j++) {
        dec->vector[j] = j;
        dec->prevfilt[j] = j * 1000;
        dec->tmp1[j] = j + 1;
        dec->tmp2[j] = j + 2;
        dec->tmp3[j] = j + 3;
        dec->cvector[j] = j + 4;
    }
    
    for (int j = 0; j < 2; j++) {
        dec->offset1[j] = j * 100;
    }
    
    for (int j = 0; j < 4; j++) {
        dec->offset2[j] = j * 200;
        dec->pulseoff[j] = j * 300;
        dec->pulsepos[j] = j * 400;
        dec->pulseval[j] = j * 500;
    }
    
    dec->flag = 1;
    
    for (int j = 0; j < 146; j++) {
        dec->filtbuf[j] = j * 10;
    }
    
    dec->filtval = 999;
    
    for (int j = 0; j < 60; j++) {
        dec->newvec[j] = j * 7;
    }
    
    for (int j = 0; j < 32; j++) {
        dec->filters[j] = j * 50;
    }
}