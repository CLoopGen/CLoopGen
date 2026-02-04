#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

u32 Te0[256];
u32 Te1[256];
u32 Te2[256];
u32 Te3[256];

u32 rk_storage[32768];  // Large enough to support multiple rounds and prevent overflow
u32 *rk = rk_storage;

u32 s0 = 0, s1 = 0, s2 = 0, s3 = 0;
u32 t0 = 0, t1 = 0, t2 = 0, t3 = 0;
int r = 1024;  // Number of iterations to achieve ~0.01 sec runtime

void init_vars() {
    // Initialize Te* tables with dummy data (bit-slicing pattern)
    for (int i = 0; i < 256; ++i) {
        Te0[i] = 0x01010101U * i;
        Te1[i] = 0x02020202U * i;
        Te2[i] = 0x04040404U * i;
        Te3[i] = 0x08080808U * i;
    }

    // Initialize state variables to non-zero values to ensure varied access
    s0 = 0xdeadbeefU;
    s1 = 0xbadc0deU;
    s2 = 0xf00dcafeU;
    s3 = 0xba5eba11U;

    // Initialize round key storage: fill with predictable pattern
    // Ensure at least several blocks worth of keys to support deep iterations
    for (int i = 0; i < 32768; ++i) {
        rk_storage[i] = 0x5a5a5a5aU ^ (i * 0x00010001U);
    }

    // Set initial rk pointer offset to avoid immediate out-of-bounds
    rk = rk_storage;

    // Set iteration count to stay well within bounds of rk array
    // Each loop iteration consumes 8 u32s, so with r=1024, we use 8192 entries
    r = 1024;
}