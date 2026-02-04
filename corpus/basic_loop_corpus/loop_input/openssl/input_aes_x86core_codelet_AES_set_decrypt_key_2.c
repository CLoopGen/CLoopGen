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

static AES_KEY key_data;
static u32 rk_data[1024];

void init_vars() {
    key = &key_data;
    rk = rk_data;
    i = 0;
    j = 0;
    
    key->rounds = 14;
    
    for (int idx = 0; idx < 1024; idx++) {
        rk_data[idx] = 0x12345678U ^ idx;
    }
}