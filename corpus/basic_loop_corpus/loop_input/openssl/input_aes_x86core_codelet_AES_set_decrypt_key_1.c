#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};

typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

AES_KEY *key;
u32 *rk;
int i;
int j;
u32 temp;

void init_vars() {
    key = malloc(sizeof(AES_KEY));
    key->rounds = 14; // Typical AES-256 rounds
    int total_size = 4 * (key->rounds + 1) * 4; // Ensure sufficient size, aligned to block operations
    rk = malloc(total_size * sizeof(u32));

    for (int idx = 0; idx < total_size; ++idx) {
        rk[idx] = idx * 31; // Arbitrary initialization
    }
}