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
    // Variant 2: Strided memory access with stride of 2, processing alternating blocks
    int stride = 2;
    int rounds = key->rounds;
    int n = 4 * rounds;
    int mid = n / 2;

    // Process elements with a strided pattern: handle even then odd indices within chunks
    for (i = 0; i < mid; i += 8) {  // Double step to maintain 4-element logic over strided access
        int indices[8];
        // Interleaved index generation: low-mid and high-mid parts with stride
        for (int s = 0; s < 4; s++) {
            indices[s]     = (i + 2*s) % mid;                    // Forward strided in first half
            indices[s+4]   = n - 4 - (i + 2*s) % mid;           // Corresponding reverse in second half
        }

        // Swap in strided groups of 4 logical elements
        for (int s = 0; s < 4; s++) {
            temp = rk[indices[s]];
            rk[indices[s]] = rk[indices[s+4]];
            rk[indices[s+4]] = temp;
        }
    }
}
