#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

GCM128_CONTEXT *ctx;
unsigned char *aad;
size_t len = 131072; // ~128KB of data for ~0.01 sec runtime
size_t i;

void init_vars() {
    ctx = (GCM128_CONTEXT*)calloc(1, sizeof(GCM128_CONTEXT));
    if (!ctx) exit(1);

    aad = (unsigned char*)malloc(len);
    if (!aad) exit(1);

    memset(ctx->Xi.c, 0, 16);
    memset(aad, 0xAA, len); // Initialize with non-zero pattern

    // Ensure no out-of-bounds access: loop runs from 0 to len-1,
    // but Xi.c is only 16 bytes, so cap 'len' at 16 for safe execution
    len = 16;
}