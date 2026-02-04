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
extern int16_t *ptr0;
extern int16_t *ptr1;
extern  int16_t *filter;
extern int i;
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 60; i += 2) {
    int t0 = (ptr0[0] * filter[0] + ptr0[1] * filter[1] + 8192) >> 14;
    int t1 = (ptr0[2] * filter[0] + ptr0[3] * filter[1] + 8192) >> 14;
    ptr0 += 2;
    dec->newvec[i] = t0;
    ptr1[i] = t0;
    if (i + 1 < 60) {
        dec->newvec[i+1] = t1;
        ptr1[i+1] = t1;
    }
}
}
