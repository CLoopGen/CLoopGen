#include <stdio.h>
#include <inttypes.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union {
        u64 u[2];
        u8 c[16];
    } nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

CCM128_CONTEXT *ctx;
unsigned int i;
unsigned int L = 4; // Ensures 15-L = 11, so loop runs from 11 to 15 inclusive

static CCM128_CONTEXT ctx_storage;

void init_vars() {
    ctx = &ctx_storage;
    L = 4; // Set L to ensure valid range: i from 11 to 15
}

void dummy_block(const unsigned char *in, unsigned char *out, const void *key) {
    // Dummy function implementation
}