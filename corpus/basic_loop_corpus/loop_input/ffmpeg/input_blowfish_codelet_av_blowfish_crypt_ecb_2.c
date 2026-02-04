#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct AVBlowfish {
    uint32_t p[18];
    uint32_t s[4][256];
} AVBlowfish;

AVBlowfish *ctx;
uint32_t Xl;
uint32_t Xr;
int i;

void init_vars() {
    ctx = (AVBlowfish*)malloc(sizeof(AVBlowfish));
    if (!ctx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 18; j++) {
        ctx->p[j] = 0x12345678 ^ (j * 0x9E3779B9);
    }

    for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 256; l++) {
            ctx->s[k][l] = 0xABCDEF01 ^ (k * 256 + l) * 0x9E3779B9;
        }
    }

    Xl = 0xCAFEBABE;
    Xr = 0xDEADBEEF;

    i = 0;
}