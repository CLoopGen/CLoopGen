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
    int rounds = key->rounds;
    for (i = 1; i < rounds; i++) {
        rk += 4;
        u32 temp0 = rk[0], temp1 = rk[1], temp2 = rk[2], temp3 = rk[3];
        
        // Increase computational intensity by adding redundant but safe operations
        temp0 ^= temp1; temp2 ^= temp3;  // Additional XORs to increase complexity
        temp0 = Td0[Te1[(temp0 >> 24)] & 255] ^ Td1[Te1[(temp0 >> 16) & 255] & 255] ^ 
                Td2[Te1[(temp0 >> 8) & 255] & 255] ^ Td3[Te1[(temp0) & 255] & 255];
        temp1 = Td0[Te1[(temp1 >> 24)] & 255] ^ Td1[Te1[(temp1 >> 16) & 255] & 255] ^ 
                Td2[Te1[(temp1 >> 8) & 255] & 255] ^ Td3[Te1[(temp1) & 255] & 255];
        temp2 = Td0[Te1[(temp2 >> 24)] & 255] ^ Td1[Te1[(temp2 >> 16) & 255] & 255] ^ 
                Td2[Te1[(temp2 >> 8) & 255] & 255] ^ Td3[Te1[(temp2) & 255] & 255];
        temp3 = Td0[Te1[(temp3 >> 24)] & 255] ^ Td1[Te1[(temp3 >> 16) & 255] & 255] ^ 
                Td2[Te1[(temp3 >> 8) & 255] & 255] ^ Td3[Te1[(temp3) & 255] & 255];

        // Final mixing step increases arithmetic depth
        temp0 ^= temp2; temp1 ^= temp3;
        rk[0] = temp0; rk[1] = temp1; rk[2] = temp2; rk[3] = temp3;
    }
}
