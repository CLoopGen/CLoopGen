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
    int step, idx1, idx2;
    int trip_count = (key->rounds) / 2;
    for (i = 0; i < trip_count; ++i) {
        step = 4 * i;
        idx1 = step;
        idx2 = 4 * (key->rounds) - 4 - step;
        if (idx1 >= idx2) break;
        for (j = 0; j < 4; ++j) {
            temp = rk[idx1 + j];
            rk[idx1 + j] = rk[idx2 + j];
            rk[idx2 + j] = temp;
        }
    }
}
