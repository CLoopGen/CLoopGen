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
    // Variant 2: Strided memory access with step size of 2 elements, processing every other group
    int len = 4 * (key->rounds);
    int step = 8; // Stride of two groups (each group is 4 u32)
    for (i = 0; i < len / 2; i += step) {
        // Process two blocks per iteration with strided access
        int forward_idx = i;
        int backward_idx = len - i - 8;

        // Swap first block of 4 elements
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

        // Second block in the group if within bounds
        if (forward_idx + 4 < backward_idx) {
            temp = rk[forward_idx + 4];
            rk[forward_idx + 4] = rk[backward_idx - 4];
            rk[backward_idx - 4] = temp;

            temp = rk[forward_idx + 5];
            rk[forward_idx + 5] = rk[backward_idx - 3];
            rk[backward_idx - 3] = temp;

            temp = rk[forward_idx + 6];
            rk[forward_idx + 6] = rk[backward_idx - 2];
            rk[backward_idx - 2] = temp;

            temp = rk[forward_idx + 7];
            rk[forward_idx + 7] = rk[backward_idx - 1];
            rk[backward_idx - 1] = temp;
        }
    }
}
