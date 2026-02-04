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

extern TSContext *dec;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1[8], temp2[8];
    for (i = 0; i < 8; i++) {
        temp1[i] = (dec->cvector[i] * 21846 + dec->prevfilt[i] * 10923 + 16384) >> 15;
        temp2[i] = (dec->cvector[i] * 10923 + dec->prevfilt[i] * 21846 + 16384) >> 15;
    }
    for (i = 0; i < 8; i++) {
        dec->filters[i + 0] = temp1[i];
        dec->filters[i + 8] = temp2[i];
    }
}
