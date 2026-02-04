#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

extern AVXTEA *ctx;
extern uint32_t v0;
extern uint32_t v1;
extern int i;
extern uint32_t delta;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (stride of 2, wrapping using modulo)
    uint32_t stride = 2;
    sum = 0; // Reset sum to ensure predictable indexing
    for (i = 0; i < 32; i++) {
        uint32_t idx1 = ((sum >> 11) & 3) * stride % 16; // Strided access in key array
        uint32_t idx2 = (sum & 3) * stride % 16;
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + ctx->key[idx1]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + ctx->key[idx2]);
    }
}
