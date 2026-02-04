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
    uint32_t local_v0 = v0, local_v1 = v1, local_sum = sum;
    const uint32_t delta_local = delta;
    for (i = 0; i < 32; i++) {
        local_v1 -= (((local_v0 << 4) ^ (local_v0 >> 5)) + local_v0) ^ (local_sum + ctx->key[(local_sum >> 11) & 3]);
        local_sum -= delta_local;
        local_v0 -= (((local_v1 << 4) ^ (local_v1 >> 5)) + local_v1) ^ (local_sum + ctx->key[local_sum & 3]);
    }
    v0 = local_v0;
    v1 = local_v1;
    sum = local_sum;
}
