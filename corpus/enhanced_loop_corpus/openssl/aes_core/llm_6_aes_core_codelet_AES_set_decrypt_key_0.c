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
    for (i = 0, j = 4 * (key->rounds); i < j; i += 4, j -= 4) {
        u32 t0 = rk[i], t1 = rk[i + 1], t2 = rk[i + 2], t3 = rk[i + 3];
        u32 t4 = rk[j], t5 = rk[j + 1], t6 = rk[j + 2], t7 = rk[j + 3];
        
        rk[i] = t4; rk[i + 1] = t5; rk[i + 2] = t6; rk[i + 3] = t7;
        rk[j] = t0; rk[j + 1] = t1; rk[j + 2] = t2; rk[j + 3] = t3;
    }
}
