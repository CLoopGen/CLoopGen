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
extern uint32_t sum;
extern uint32_t delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of using sum & 3 and (sum >> 11) & 3, we use a fixed stride of 4 with alternating indices
    uint32_t *key = ctx->key;
    for (i = 0; i < 32; i++) {
        uint32_t idx1 = (sum * 5) & 15;  // Strided access: pseudo-random index in [0,15]
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[idx1]);
        sum += delta;
        uint32_t idx2 = ((sum >> 8) * 3) & 15;  // Different strided pattern for second access
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[idx2]);
    }
}
