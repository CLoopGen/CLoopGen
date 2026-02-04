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

AVXTEA *ctx;
uint8_t key[16];
int i;

void init_vars() {
    // Allocate and initialize ctx
    ctx = (AVXTEA*)aligned_alloc(32, sizeof(AVXTEA));
    
    // Initialize key with dummy data
    for (int j = 0; j < 16; j++) {
        key[j] = (uint8_t)(j * 17);
    }

    // Ensure proper initialization of other loop-related variables if needed
    i = 0;
}