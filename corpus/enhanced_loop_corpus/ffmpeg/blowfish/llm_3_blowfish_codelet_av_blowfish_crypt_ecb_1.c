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



void loop() {
    // Variant 2: Consecutive Array Access via Pointer Arithmetic
    // Reorganize S-box accesses to use pointer arithmetic with consecutive indexing,
    // simulating a flattened view of s[4][256] as a linear array to change access pattern.
    uint32_t *s_flat = &ctx->s[0][0]; // Treat 4x256 S-box as a single 1024-element array

    for (i = 16; i > 0; i -= 2) {
        uint8_t xh = Xl >> 24, xm1 = (Xl >> 16) & 255, xm2 = (Xl >> 8) & 255, xl = Xl & 255;
        uint8_t yh = Xr >> 24, ym1 = (Xr >> 16) & 255, ym2 = (Xr >> 8) & 255, yl = Xr & 255;

        // Use consecutive layout: s[0][a] = s_flat[a], s[1][b] = s_flat[256 + b], etc.
        Xr ^= (((s_flat[xh] + s_flat[256 + xm1]) ^ s_flat[512 + xm2]) + s_flat[768 + xl]) ^ ctx->p[i];
        
        Xl ^= (((s_flat[yh] + s_flat[256 + ym1]) ^ s_flat[512 + ym2]) + s_flat[768 + yl]) ^ ctx->p[i - 1];
    }
}
