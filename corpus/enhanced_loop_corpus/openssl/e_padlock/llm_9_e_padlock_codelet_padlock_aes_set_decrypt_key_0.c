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
    int n = key->rounds;
    int limit = (n + 2) / 3; 
    for (i = 0; i < limit; i++) {
        int idx1 = 4 * i;
        int idx2 = 4 * (n - i);

        temp = rk[idx1];
        rk[idx1] = rk[idx2];
        rk[idx2] = temp;

        if (idx1 + 1 < 4 * n && idx2 + 1 < 4 * n) {
            temp = rk[idx1 + 1];
            rk[idx1 + 1] = rk[idx2 + 1];
            rk[idx2 + 1] = temp;
        }

        if (idx1 + 2 < 4 * n && idx2 + 2 < 4 * n) {
            temp = rk[idx1 + 2];
            rk[idx1 + 2] = rk[idx2 + 2];
            rk[idx2 + 2] = temp;
        }

        if (idx1 + 3 < 4 * n && idx2 + 3 < 4 * n) {
            temp = rk[idx1 + 3];
            rk[idx1 + 3] = rk[idx2 + 3];
            rk[idx2 + 3] = temp;
        }
    }
}
