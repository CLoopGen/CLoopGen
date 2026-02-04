#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};

typedef struct aes_key_st AES_KEY;

extern u64 Td[256];
extern AES_KEY *key;
extern u32 *rk;
extern u32 s0;
extern u32 s1;
extern u32 s2;
extern u32 s3;
extern u32 t[4];
extern int r;

u64 Td[256];
AES_KEY *key;
u32 *rk_storage;
u32 *rk;
u32 s0 = 0x12345678;
u32 s1 = 0x9abcdef0;
u32 s2 = 0xfedcba98;
u32 s3 = 0x76543210;
u32 t[4];
int r;

void init_vars() {
    key = (AES_KEY*)malloc(sizeof(AES_KEY));
    if (!key) exit(1);

    for (int i = 0; i < 60; i++) {
        key->rd_key[i] = 0xdeadbeef ^ (i * 0x9e3779b9);
    }

    const int min_rounds = 10;
    const int target_time_ms_per_iter = 10;
    const int base_iters = 10000;
    const int scale_factor = 1;
    int effective_rounds = min_rounds + (target_time_ms_per_iter * scale_factor);
    key->rounds = effective_rounds > 14 ? effective_rounds : 14;

    rk_storage = (u32*)calloc(1024, sizeof(u32));
    if (!rk_storage) exit(1);

    for (int i = 0; i < 1024; i++) {
        rk_storage[i] = 0xc0defeed ^ (i * 0x1f3b5d79);
    }

    rk = rk_storage;

    for (int i = 0; i < 256; i++) {
        Td[i] = ((u64)(0xa5a5a5a5 ^ i) << 32) | (0x5a5a5a5a ^ (i << 8));
    }

    r = key->rounds - 2;
    rk += 8;
}