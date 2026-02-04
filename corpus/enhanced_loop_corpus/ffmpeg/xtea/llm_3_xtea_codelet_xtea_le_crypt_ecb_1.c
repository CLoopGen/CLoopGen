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
    // Variant 2: Indirect memory access via precomputed index array
    uint32_t indices[32];
    // Precompute indirect indices with a non-linear pattern
    for (int j = 0; j < 32; j++) {
        indices[j] = (j * j + 3) & 15; // Quadratic probing for indirect access
    }
    for (i = 0; i < 32; i++) {
        uint32_t idx1 = indices[i]; // Use indirect index for first access
        uint32_t idx2 = indices[(i + 5) % 32]; // Shifted indirect index
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + ctx->key[idx1]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + ctx->key[idx2]);
    }
}
