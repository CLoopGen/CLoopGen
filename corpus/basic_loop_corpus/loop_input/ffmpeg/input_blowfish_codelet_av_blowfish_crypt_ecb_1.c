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
    // Allocate and initialize Blowfish context
    ctx = (AVBlowfish *)malloc(sizeof(AVBlowfish));
    if (!ctx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize p-array with pseudo-random values
    uint32_t seed = 0x12345678;
    for (int j = 0; j < 18; j++) {
        seed = seed * 1103515245 + 12345;
        ctx->p[j] = seed;
    }

    // Initialize S-boxes with pseudo-random values
    for (int box = 0; box < 4; box++) {
        for (int k = 0; k < 256; k++) {
            seed = seed * 1103515245 + 12345;
            ctx->s[box][k] = seed;
        }
    }

    // Initialize Xl and Xr to non-zero values within uint32_t range
    Xl = 0xDEADBEEF;
    Xr = 0xBADDCAFE;

    // Ensure consistent initial state for loop
    i = 16;
}

// Force compiler to not optimize away the variables
__attribute__((used)) void *get_ctx() { return ctx; }