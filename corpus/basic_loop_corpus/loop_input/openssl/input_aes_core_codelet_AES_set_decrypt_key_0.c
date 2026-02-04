#include <stdio.h>
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

static u32 rk_buffer[1024];
static AES_KEY key_instance;

void init_vars() {
    key = &key_instance;
    rk = rk_buffer;
    key->rounds = 10;  // AES-128: 10 rounds, so j starts at 4 * 10 = 40
    for (int idx = 0; idx < 1024; ++idx) {
        rk[idx] = idx * 314159;  // Arbitrary non-zero pattern
    }
}