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
    for (i = 1; i < (key->rounds) - 1; i += 2) {
        rk += 8;
        u32 r0 = rk[0], r1 = rk[1], r2 = rk[2], r3 = rk[3];
        u32 r4 = rk[4], r5 = rk[5], r6 = rk[6], r7 = rk[7];

        rk[0] = Td0[Te1[r0 >> 24] & 255] ^ Td1[Te1[(r0 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r0 >> 8) & 255] & 255] ^ Td3[Te1[r0 & 255] & 255];
        rk[1] = Td0[Te1[r1 >> 24] & 255] ^ Td1[Te1[(r1 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r1 >> 8) & 255] & 255] ^ Td3[Te1[r1 & 255] & 255];
        rk[2] = Td0[Te1[r2 >> 24] & 255] ^ Td1[Te1[(r2 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r2 >> 8) & 255] & 255] ^ Td3[Te1[r2 & 255] & 255];
        rk[3] = Td0[Te1[r3 >> 24] & 255] ^ Td1[Te1[(r3 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r3 >> 8) & 255] & 255] ^ Td3[Te1[r3 & 255] & 255];

        rk[4] = Td0[Te1[r4 >> 24] & 255] ^ Td1[Te1[(r4 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r4 >> 8) & 255] & 255] ^ Td3[Te1[r4 & 255] & 255];
        rk[5] = Td0[Te1[r5 >> 24] & 255] ^ Td1[Te1[(r5 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r5 >> 8) & 255] & 255] ^ Td3[Te1[r5 & 255] & 255];
        rk[6] = Td0[Te1[r6 >> 24] & 255] ^ Td1[Te1[(r6 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r6 >> 8) & 255] & 255] ^ Td3[Te1[r6 & 255] & 255];
        rk[7] = Td0[Te1[r7 >> 24] & 255] ^ Td1[Te1[(r7 >> 16) & 255] & 255] ^ 
                Td2[Te1[(r7 >> 8) & 255] & 255] ^ Td3[Te1[r7 & 255] & 255];
    }
}
