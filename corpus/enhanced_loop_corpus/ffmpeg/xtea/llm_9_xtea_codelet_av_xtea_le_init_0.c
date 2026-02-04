#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern AVXTEA *ctx;
extern  uint8_t key[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i += 1) {
        ctx->key[i << 1] = ((const union unaligned_32 *)(key + (i << 3)))->l;
        ctx->key[(i << 1) + 1] = ((const union unaligned_32 *)(key + (i << 3) + 4))->l;
        // Reduced trip count but unrolled-like access pattern, changing computational density
    }
}
