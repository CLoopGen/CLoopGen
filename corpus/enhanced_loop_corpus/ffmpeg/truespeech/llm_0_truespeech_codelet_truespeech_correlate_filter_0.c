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

extern  int16_t ts_decay_994_1000[8];
extern TSContext *dec;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < 2; outer_i++) {
        for (i = 0; i < 4; i++) {
            dec->cvector[i + outer_i * 4] = (dec->cvector[i + outer_i * 4] * ts_decay_994_1000[i + outer_i * 4]) >> 15;
        }
    }
}
