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
    // Variant 2: Strided memory access with reverse traversal and stride of 4
    int rounds = key->rounds;
    int len = 4 * rounds;
    int stride = 4;
    for (i = 0; i < len / 2; i += stride) {
        int forward_idx = i;
        int backward_idx = len - stride - i;
        temp = rk[forward_idx];
        rk[forward_idx] = rk[backward_idx];
        rk[backward_idx] = temp;
        temp = rk[forward_idx + 1];
        rk[forward_idx + 1] = rk[backward_idx + 1];
        rk[backward_idx + 1] = temp;
        temp = rk[forward_idx + 2];
        rk[forward_idx + 2] = rk[backward_idx + 2];
        rk[backward_idx + 2] = temp;
        temp = rk[forward_idx + 3];
        rk[forward_idx + 3] = rk[backward_idx + 3];
        rk[backward_idx + 3] = temp;
    }
}
