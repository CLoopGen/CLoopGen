#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef uint64_t u64;

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};

typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;
typedef unsigned char u8;

u64 Te[256];
AES_KEY *key;
u32 *rk;
u32 s0;
u32 s1;
u32 s2;
u32 s3;
u32 t[4];
int r;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        Te[i] = ((u64)(i ^ 0xff) << 56) | ((u64)i << 40) | ((u64)(i << 4) << 24) | ((u64)(i >> 4) << 16) | (u64)(i * 3) << 8 | (i ^ 0x55);
    }

    key = (AES_KEY *)malloc(sizeof(AES_KEY));
    key->rounds = 14;

    for (int i = 0; i < 60; ++i) {
        key->rd_key[i] = 0xdeadbeef ^ (i * 65537);
    }

    rk = (u32 *)aligned_alloc(16, 1024 * sizeof(u32));
    for (int i = 0; i < 1024; ++i) {
        rk[i] = 0xc0debabe ^ (i * 977);
    }

    s0 = 0x12345678;
    s1 = 0x9abcdef0;
    s2 = 0xfedcba98;
    s3 = 0x76543210;

    t[0] = t[1] = t[2] = t[3] = 0;

    r = 0;
}