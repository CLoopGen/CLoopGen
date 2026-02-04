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

static AES_KEY key_storage;
static u32 rk_storage[1024];

void init_vars() {
    key = &key_storage;
    rk = rk_storage;
    
    key->rounds = 14;
    
    for (int idx = 0; idx < 1024; idx++) {
        rk[idx] = 0x12345678U ^ idx;
    }
}