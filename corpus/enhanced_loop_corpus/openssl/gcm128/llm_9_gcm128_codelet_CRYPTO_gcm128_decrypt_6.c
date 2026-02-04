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
    for (i = 0; i < 8 / sizeof(size_t); ++i) {
        size_t val1 = in_t[i] ^ ctx->EKi.t[i];
        size_t val2 = val1 ^ (val1 << 1) ^ (val1 >> 1);
        out_t[i] = val2;
    }
}
