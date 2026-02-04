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
    int limit = 4 * (key->rounds);
    for (i = 0; i < limit; i += 8) {
        if (i + 4 >= limit) break;
        temp = rk[i];
        rk[i] = rk[limit - 4];
        rk[limit - 4] = temp;
        temp = rk[i + 1];
        rk[i + 1] = rk[limit - 3];
        rk[limit - 3] = temp;
        temp = rk[i + 2];
        rk[i + 2] = rk[limit - 2];
        rk[limit - 2] = temp;
        temp = rk[i + 3];
        rk[i + 3] = rk[limit - 1];
        rk[limit - 1] = temp;
        limit -= 4;
    }
}
