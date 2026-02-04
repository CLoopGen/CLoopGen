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

typedef size_t size_t_aX __attribute__((aligned(1)));

extern GCM128_CONTEXT *ctx;
extern size_t i;
extern size_t_aX *out_t;
extern  size_t_aX *in_t;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Flattened version with reduced effective loop depth (though original is already flat)
    // To decrease depth meaningfully, we unroll partially based on typical size assumptions.
    // Assuming sizeof(size_t) is 8 or 4, so 16/sizeof(size_t) is either 2 or 4.
    // Here we assume sizeof(size_t) == 8 -> 2 iterations; if smaller, guard extra writes.

    const size_t n = 16 / sizeof(size_t);

    if (n >= 1) out_t[0] = in_t[0] ^ ctx->EKi.t[0];
    if (n >= 2) out_t[1] = in_t[1] ^ ctx->EKi.t[1];
    if (n >= 3) out_t[2] = in_t[2] ^ ctx->EKi.t[2];
    if (n >= 4) out_t[3] = in_t[3] ^ ctx->EKi.t[3];
}
