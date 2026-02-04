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
    int local_i, local_j;
    u32 temp1, temp2, temp3, temp4;
    int rounds = local_key->rounds;
    for (local_i = 0, local_j = 4 * rounds; local_i < local_j; local_i += 4, local_j -= 4) {
        temp1 = local_rk[local_i];
        temp2 = local_rk[local_i + 1];
        temp3 = local_rk[local_i + 2];
        temp4 = local_rk[local_i + 3];

        local_rk[local_i] = local_rk[local_j];
        local_rk[local_i + 1] = local_rk[local_j + 1];
        local_rk[local_i + 2] = local_rk[local_j + 2];
        local_rk[local_i + 3] = local_rk[local_j + 3];

        local_rk[local_j] = temp1;
        local_rk[local_j + 1] = temp2;
        local_rk[local_j + 2] = temp3;
        local_rk[local_j + 3] = temp4;
    }
}
