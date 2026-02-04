#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

extern  u32 Te1[256];
extern  u32 Td0[256];
extern  u32 Td1[256];
extern  u32 Td2[256];
extern  u32 Td3[256];
extern AES_KEY *key;
extern u32 *rk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < (key->rounds); i++) {
    rk += 4;
    int indices[4] = {0, 1, 2, 3};
    for (int j = 0; j < 4; j++) {
        u32 val = rk[indices[j]];
        rk[indices[j]] = 
            Td0[Te1[val >> 24] & 255] ^
            Td1[Te1[(val >> 16) & 255] & 255] ^
            Td2[Te1[(val >> 8) & 255] & 255] ^
            Td3[Te1[val & 255] & 255];
    }
}
}
