#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

AVXTEA *ctx;
uint32_t v0;
uint32_t v1;
int i;
uint32_t sum;
uint32_t delta;

static AVXTEA ctx_storage;

void init_vars() {
    // Initialize the context pointer to point to our allocated storage
    ctx = &ctx_storage;

    // Initialize key data to non-zero values to ensure realistic computation
    for (int k = 0; k < 16; k++) {
        ctx->key[k] = 0x12345678U ^ (k * 0x9ABC);
    }

    // Initialize v0 and v1 to arbitrary non-zero values
    v0 = 0xDEADBEEF;
    v1 = 0xBADCAFE;

    // Initialize sum and delta to typical TEA cipher values
    sum = 0;
    delta = 0x9E3779B9; // Standard delta value used in TEA algorithms
}

// Perform initialization of global variables
__attribute__((constructor))
static void constructor_init() {
    init_vars();
}