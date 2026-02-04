#include <stdio.h>

#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

extern AES_KEY *key;
extern u32 *rk;
extern int i;
extern int j;
extern u32 temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u32 *local_rk = rk;
    AES_KEY *local_key = key;
    int i_val, j_val;
    u32 cache[8];
    int rounds = local_key->rounds;
    for (i_val = 0, j_val = 4 * rounds; i_val < j_val; i_val += 4, j_val -= 4) {
        cache[0] = local_rk[i_val];
        cache[1] = local_rk[i_val + 1];
        cache[2] = local_rk[i_val + 2];
        cache[3] = local_rk[i_val + 3];
        cache[4] = local_rk[j_val];
        cache[5] = local_rk[j_val + 1];
        cache[6] = local_rk[j_val + 2];
        cache[7] = local_rk[j_val + 3];

        local_rk[i_val] = cache[4];
        local_rk[i_val + 1] = cache[5];
        local_rk[i_val + 2] = cache[6];
        local_rk[i_val + 3] = cache[7];
        local_rk[j_val] = cache[0];
        local_rk[j_val + 1] = cache[1];
        local_rk[j_val + 2] = cache[2];
        local_rk[j_val + 3] = cache[3];
    }
}
