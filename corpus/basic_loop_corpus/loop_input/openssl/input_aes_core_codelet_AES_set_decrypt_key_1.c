#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};

typedef struct aes_key_st AES_KEY;

u32 Te1[256] = {0};
u32 Td0[256] = {0};
u32 Td1[256] = {0};
u32 Td2[256] = {0};
u32 Td3[256] = {0};

AES_KEY *key;
u32 *rk;
int i;

void init_vars() {
    for (int j = 0; j < 256; j++) {
        Te1[j] = j * 0x01010101U;
        Td0[j] = j * 0x02020202U;
        Td1[j] = j * 0x03030303U;
        Td2[j] = j * 0x04040404U;
        Td3[j] = j * 0x05050505U;
    }

    key = (AES_KEY*)malloc(sizeof(AES_KEY));
    if (!key) exit(1);
    key->rounds = 14;

    u32 *full_rk = (u32*)calloc(60 + 16, sizeof(u32));
    if (!full_rk) exit(1);

    memcpy(full_rk, key->rd_key, 60 * sizeof(u32));
    rk = full_rk - 4;
}