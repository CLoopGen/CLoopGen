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

extern  int16_t ts_pulse_scales[64];
extern TSContext *dec;
extern int quart;
extern int16_t tmp[7];
extern int i;
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 7; i++) {
        t = (dec->pulseval[quart] & 3);
        dec->pulseval[quart] >>= 2;
        if (t >= 0 && t < 4) {
            tmp[6 - i] = ts_pulse_scales[dec->pulseoff[quart] * 4 + t];
        } else {
            tmp[6 - i] = ts_pulse_scales[0];
        }
    }
}
