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
    // Reduced effective trip count with increased per-iteration operations using word-level XOR
    size_t full_words = len / 8;
    u64 *xi64 = (u64 *)ctx->Xi.c;
    u64 *iv64 = (u64 *)iv;

    for (i = 0; i < full_words; ++i) {
        xi64[i] ^= iv64[i];
    }

    // Handle remaining bytes
    for (; i * 8 < len; ++(i)) {
        size_t idx = i * 8;
        if (idx < len) ctx->Xi.c[idx] ^= iv[idx];
        if (idx + 1 < len) ctx->Xi.c[idx + 1] ^= iv[idx + 1];
        if (idx + 2 < len) ctx->Xi.c[idx + 2] ^= iv[idx + 2];
        if (idx + 3 < len) ctx->Xi.c[idx + 3] ^= iv[idx + 3];
        if (idx + 4 < len) ctx->Xi.c[idx + 4] ^= iv[idx + 4];
        if (idx + 5 < len) ctx->Xi.c[idx + 5] ^= iv[idx + 5];
        if (idx + 6 < len) ctx->Xi.c[idx + 6] ^= iv[idx + 6];
        if (idx + 7 < len) ctx->Xi.c[idx + 7] ^= iv[idx + 7];
    }
}
