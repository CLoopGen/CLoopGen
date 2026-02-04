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

typedef size_t size_t_aX __attribute__((aligned(1)));

GCM128_CONTEXT *ctx;
size_t i;
size_t_aX *out_t;
size_t_aX *in_t;

void init_vars() {
    const size_t data_size = 1024 * 1024; // ~1MB to ensure loop runs long enough
    const size_t num_elements = data_size / sizeof(size_t_aX);

    in_t = aligned_alloc(1, data_size);
    out_t = aligned_alloc(1, data_size);
    ctx = malloc(sizeof(GCM128_CONTEXT));

    if (!in_t || !out_t || !ctx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < num_elements; ++j) {
        in_t[j] = j * 0xdeadbeefULL;
    }

    memset(ctx, 0, sizeof(GCM128_CONTEXT));
    ctx->EKi.t[0] = 0x0123456789abcdefULL;
    ctx->EKi.t[1] = 0xfedcba9876543210ULL;

    i = 0;
}