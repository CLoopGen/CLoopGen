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
    u32 t0, t1, t2, t3;
    for (i = 0, j = 4 * (key->rounds); i < j; i += 4, j -= 4) {
        t0 = rk[i];      t1 = rk[i + 1];
        t2 = rk[i + 2];  t3 = rk[i + 3];
        rk[i] = rk[j];   rk[i + 1] = rk[j + 1];
        rk[i + 2] = rk[j + 2]; rk[i + 3] = rk[j + 3];
        rk[j] = t0;      rk[j + 1] = t1;
        rk[j + 2] = t2;  rk[j + 3] = t3;
    }
}
