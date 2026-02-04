#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVBlowfish {
    uint32_t p[18];
    uint32_t s[4][256];
} AVBlowfish;

extern AVBlowfish *ctx;
extern uint32_t Xl;
extern uint32_t Xr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i > 0; i -= 2) {
        if (Xl != Xr) {
            Xr ^= (((ctx->s[0][Xl >> 24] + ctx->s[1][(Xl >> 16) & 255]) ^ ctx->s[2][(Xl >> 8) & 255]) + ctx->s[3][Xl & 255]) ^ ctx->p[i];
        }
        ;
        if (Xr != 0) {
            Xl ^= (((ctx->s[0][Xr >> 24] + ctx->s[1][(Xr >> 16) & 255]) ^ ctx->s[2][(Xr >> 8) & 255]) + ctx->s[3][Xr & 255]) ^ ctx->p[i - 1];
        }
        ;
    }
}
