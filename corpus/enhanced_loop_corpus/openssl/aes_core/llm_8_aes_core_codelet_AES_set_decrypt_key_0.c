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
    int start = 0;
    int end = 4 * (key->rounds);
    for (i = start; i < end; i += 8, end -= 8) {
        if (i + 3 >= end - 3) break;

        temp = rk[i];
        rk[i] = rk[end - 4];
        rk[end - 4] = temp;

        temp = rk[i + 1];
        rk[i + 1] = rk[end - 3];
        rk[end - 3] = temp;

        temp = rk[i + 2];
        rk[i + 2] = rk[end - 2];
        rk[end - 2] = temp;

        temp = rk[i + 3];
        rk[i + 3] = rk[end - 1];
        rk[end - 1] = temp;

        temp = rk[i + 4];
        rk[i + 4] = rk[end - 8];
        rk[end - 8] = temp;

        temp = rk[i + 5];
        rk[i + 5] = rk[end - 7];
        rk[end - 7] = temp;

        temp = rk[i + 6];
        rk[i + 6] = rk[end - 6];
        rk[end - 6] = temp;

        temp = rk[i + 7];
        rk[i + 7] = rk[end - 5];
        rk[end - 5] = temp;
    }
}
