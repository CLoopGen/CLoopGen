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
    if (i % 2 == 0) {
        rk[0] = Td0[Te1[(rk[0] >> 24)] & 255] ^ Td1[Te1[(rk[0] >> 16) & 255] & 255] ^ Td2[Te1[(rk[0] >> 8) & 255] & 255] ^ Td3[Te1[(rk[0]) & 255] & 255];
        rk[1] = Td0[Te1[(rk[1] >> 24)] & 255] ^ Td1[Te1[(rk[1] >> 16) & 255] & 255] ^ Td2[Te1[(rk[1] >> 8) & 255] & 255] ^ Td3[Te1[(rk[1]) & 255] & 255];
    } else {
        rk[2] = Td0[Te1[(rk[2] >> 24)] & 255] ^ Td1[Te1[(rk[2] >> 16) & 255] & 255] ^ Td2[Te1[(rk[2] >> 8) & 255] & 255] ^ Td3[Te1[(rk[2]) & 255] & 255];
        rk[3] = Td0[Te1[(rk[3] >> 24)] & 255] ^ Td1[Te1[(rk[3] >> 16) & 255] & 255] ^ Td2[Te1[(rk[3] >> 8) & 255] & 255] ^ Td3[Te1[(rk[3]) & 255] & 255];
    }
}
}
