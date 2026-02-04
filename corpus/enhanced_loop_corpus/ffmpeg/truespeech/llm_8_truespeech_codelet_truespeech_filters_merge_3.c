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
    for (i = 0; i < 4; i++) {
        int idx = i * 2;
        int cvec0 = dec->cvector[idx];
        int cvec1 = dec->cvector[idx + 1];
        int prev0 = dec->prevfilt[idx];
        int prev1 = dec->prevfilt[idx + 1];

        dec->filters[idx + 0] = (cvec0 * 21846 + prev0 * 10923 + 16384) >> 15;
        dec->filters[idx + 1] = (cvec1 * 21846 + prev1 * 10923 + 16384) >> 15;
        dec->filters[idx + 8] = (cvec0 * 10923 + prev0 * 21846 + 16384) >> 15;
        dec->filters[idx + 9] = (cvec1 * 10923 + prev1 * 21846 + 16384) >> 15;
    }
}
