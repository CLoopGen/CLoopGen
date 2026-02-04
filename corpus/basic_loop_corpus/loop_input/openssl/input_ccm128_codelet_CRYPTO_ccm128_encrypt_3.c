#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
unsigned char *inp;
size_t len;
unsigned int i;

void init_vars() {
    len = 512 * 1024; // 512KB of data for ~0.01 sec runtime

    ctx = (CCM128_CONTEXT *)malloc(sizeof(CCM128_CONTEXT));
    if (!ctx) exit(1);

    memset(ctx, 0, sizeof(*ctx));

    inp = (unsigned char *)malloc(len);
    if (!inp) {
        free(ctx);
        exit(1);
    }

    for (size_t j = 0; j < len; ++j) {
        inp[j] = (unsigned char)(j & 0xFF);
    }

    // Ensure that the loop only accesses within cmac.c bounds [0..15]
    // So we limit i from 0 to min(len, 16)-1
    len = (len > 16) ? 16 : len;
}

void loop(); // Forward declaration

// Optional: provide a main for standalone testing (but not required per instructions)
// Not included as per request.