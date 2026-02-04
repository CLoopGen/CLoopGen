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
for (i = 8; i > 0; i--) {
    uint32_t temp = Xl;
    Xl = Xr;
    Xr = temp;

    Xr ^= ((ctx->s[0][Xl >> 24] + ctx->s[1][(Xl >> 16) & 255]) ^ ctx->s[2][(Xl >> 8) & 255]) + ctx->s[3][Xl & 255];
    Xr ^= ctx->p[2 * i];
    
    Xl ^= ((ctx->s[0][Xr >> 24] + ctx->s[1][(Xr >> 16) & 255]) ^ ctx->s[2][(Xr >> 8) & 255]) + ctx->s[3][Xr & 255];
    Xl ^= ctx->p[2 * i - 1];
}
}
