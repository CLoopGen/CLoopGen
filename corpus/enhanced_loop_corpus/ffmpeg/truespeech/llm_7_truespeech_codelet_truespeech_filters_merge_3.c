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
    for (i = 0; i < 8; i++) {
        int cvec_val = dec->cvector[i];
        int prev_val = dec->prevfilt[i];
        int scaled_cvec_1 = cvec_val * 21846;
        int scaled_prev_1 = prev_val * 10923;
        int sum1 = scaled_cvec_1 + scaled_prev_1 + 16384;
        dec->filters[i + 0] = sum1 >> 15;

        int scaled_cvec_2 = cvec_val * 10923;
        int scaled_prev_2 = prev_val * 21846;
        int sum2 = scaled_cvec_2 + scaled_prev_2 + 16384;
        dec->filters[i + 8] = sum2 >> 15;
    }
}
