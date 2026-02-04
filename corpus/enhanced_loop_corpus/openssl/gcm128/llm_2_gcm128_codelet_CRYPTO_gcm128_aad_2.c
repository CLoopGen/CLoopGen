#include <stdio.h>

#include <inttypes.h>

typedef unsigned long long u64;

typedef unsigned int u32;

typedef unsigned char u8;

union {
    u64 u[2];
    u32 d[4];
    u8 c[16];
    size_t t[2];
};


typedef struct {
    u64 hi;
    u64 lo;
} u128;

typedef void (*gcm_init_fn)(u128 *, const u64 *);

typedef void (*gcm_ghash_fn)(u64 *, const u128 *, const u8 *, size_t);

typedef void (*gcm_gmult_fn)(u64 *, const u128 *);

struct gcm_funcs_st {
    gcm_init_fn ginit;
    gcm_ghash_fn ghash;
    gcm_gmult_fn gmult;
};


typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct gcm128_context {
    union {
        u64 u[2];
        u32 d[4];
        u8 c[16];
        size_t t[2];
    } Yi, EKi, EK0, len, Xi, H;
    u128 Htable[16];
    struct gcm_funcs_st funcs;
    unsigned int mres;
    unsigned int ares;
    block128_f block;
    void *key;
    unsigned char Xn[48];
};


typedef struct gcm128_context GCM128_CONTEXT;

extern GCM128_CONTEXT *ctx;
extern  unsigned char *aad;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    size_t limit = len - (len % 2);  // Make sure we don't exceed bounds when accessing i+1
    for (i = 0; i < limit; i += 2) {
        ctx->Xi.c[i] ^= aad[i];
        ctx->Xi.c[i + 1] ^= aad[i + 1];
    }
    // Handle remaining element if len is odd
    if (len % 2 != 0) {
        ctx->Xi.c[len - 1] ^= aad[len - 1];
    }
}
