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
    for (i = 0; i < 4 * (key->rounds); i += 4) {
        for (int k = 0; k < 4; ++k) {
            int j = 4 * (key->rounds) - i;
            temp = rk[i + k];
            rk[i + k] = rk[j + k];
            rk[j + k] = temp;
        }
    }
}
