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
    uint32_t temp_Xl = Xl;
    uint32_t temp_Xr = Xr;
    for (i = 16; i > 0; i -= 2) {
        uint32_t f1 = ((ctx->s[0][temp_Xl >> 24] + ctx->s[1][(temp_Xl >> 16) & 255]) ^ ctx->s[2][(temp_Xl >> 8) & 255]) + ctx->s[3][temp_Xl & 255];
        uint32_t f2 = ((ctx->s[0][temp_Xr >> 24] + ctx->s[1][(temp_Xr >> 16) & 255]) ^ ctx->s[2][(temp_Xr >> 8) & 255]) + ctx->s[3][temp_Xr & 255];
        temp_Xr ^= f1 ^ ctx->p[i];
        temp_Xl ^= f2 ^ ctx->p[i - 1];
    }
    Xl = temp_Xl;
    Xr = temp_Xr;
}
