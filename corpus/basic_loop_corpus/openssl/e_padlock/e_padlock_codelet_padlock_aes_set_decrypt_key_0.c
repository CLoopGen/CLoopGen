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
for (i = 0 , j = 4 * (key->rounds); i < j; i += 4 , j -= 4) {
    temp = rk[i];
    rk[i] = rk[j];
    rk[j] = temp;
    temp = rk[i + 1];
    rk[i + 1] = rk[j + 1];
    rk[j + 1] = temp;
    temp = rk[i + 2];
    rk[i + 2] = rk[j + 2];
    rk[j + 2] = temp;
    temp = rk[i + 3];
    rk[i + 3] = rk[j + 3];
    rk[j + 3] = temp;
}

}
