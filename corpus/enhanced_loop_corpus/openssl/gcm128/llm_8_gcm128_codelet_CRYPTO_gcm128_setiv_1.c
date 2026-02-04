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
extern  unsigned char *iv;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t limit = (len + 7) & ~7; // Round up to nearest multiple of 8 for unrolling
    for (i = 0; i < limit; i += 8) {
        if (i < len) ctx->Xi.c[i] ^= iv[i];
        if (i + 1 < len) ctx->Xi.c[i + 1] ^= iv[i + 1];
        if (i + 2 < len) ctx->Xi.c[i + 2] ^= iv[i + 2];
        if (i + 3 < len) ctx->Xi.c[i + 3] ^= iv[i + 3];
        if (i + 4 < len) ctx->Xi.c[i + 4] ^= iv[i + 4];
        if (i + 5 < len) ctx->Xi.c[i + 5] ^= iv[i + 5];
        if (i + 6 < len) ctx->Xi.c[i + 6] ^= iv[i + 6];
        if (i + 7 < len) ctx->Xi.c[i + 7] ^= iv[i + 7];
    }
}
