#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVBlowfish {
    uint32_t p[18];
    uint32_t s[4][256];
} AVBlowfish;

extern  uint32_t orig_p[18];
extern AVBlowfish *ctx;
extern  uint8_t *key;
extern int key_len;
extern uint32_t data;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 + 2; ++i) {
        data = 0;
        // Use strided access over key with fixed stride of 1, but unroll the inner loop manually to change memory access pattern
        uint8_t chunk[4];
        for (k = 0; k < 4; ++k) {
            int idx = (j + k) % key_len;
            chunk[k] = key[idx];
        }
        j = (j + 4) % key_len;
        data = (chunk[0] << 24) | (chunk[1] << 16) | (chunk[2] << 8) | chunk[3];
        ctx->p[i] = orig_p[i] ^ data;
    }
}
