#include <stdio.h>

#include <inttypes.h>

typedef uint64_t u64;

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

typedef unsigned char u8;

extern  u64 Td[256];
extern  AES_KEY *key;
extern  u32 *rk;
extern u32 s0;
extern u32 s1;
extern u32 s2;
extern u32 s3;
extern u32 t[4];
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u32 index[4][4];
    for (rk += 8, r = key->rounds - 2; r > 0; rk += 4, r--) {
        index[0][0] = s0 & 255;       index[0][1] = (s3 >> 8) & 255;
        index[0][2] = (s2 >> 16) & 255; index[0][3] = s1 >> 24;
        index[1][0] = s1 & 255;       index[1][1] = (s0 >> 8) & 255;
        index[1][2] = (s3 >> 16) & 255; index[1][3] = s2 >> 24;
        index[2][0] = s2 & 255;       index[2][1] = (s1 >> 8) & 255;
        index[2][2] = (s0 >> 16) & 255; index[2][3] = s3 >> 24;
        index[3][0] = s3 & 255;       index[3][1] = (s2 >> 8) & 255;
        index[3][2] = (s1 >> 16) & 255; index[3][3] = s0 >> 24;

        t[0] = ((u32 *)((u8 *)Td + 0))[index[0][0]] ^ 
               ((u32 *)((u8 *)Td + 3))[index[0][1]] ^ 
               ((u32 *)((u8 *)Td + 2))[index[0][2]] ^ 
               ((u32 *)((u8 *)Td + 1))[index[0][3]] ^ rk[0];

        t[1] = ((u32 *)((u8 *)Td + 0))[index[1][0]] ^ 
               ((u32 *)((u8 *)Td + 3))[index[1][1]] ^ 
               ((u32 *)((u8 *)Td + 2))[index[1][2]] ^ 
               ((u32 *)((u8 *)Td + 1))[index[1][3]] ^ rk[1];

        t[2] = ((u32 *)((u8 *)Td + 0))[index[2][0]] ^ 
               ((u32 *)((u8 *)Td + 3))[index[2][1]] ^ 
               ((u32 *)((u8 *)Td + 2))[index[2][2]] ^ 
               ((u32 *)((u8 *)Td + 1))[index[2][3]] ^ rk[2];

        t[3] = ((u32 *)((u8 *)Td + 0))[index[3][0]] ^ 
               ((u32 *)((u8 *)Td + 3))[index[3][1]] ^ 
               ((u32 *)((u8 *)Td + 2))[index[3][2]] ^ 
               ((u32 *)((u8 *)Td + 1))[index[3][3]] ^ rk[3];

        s0 = t[0];
        s1 = t[1];
        s2 = t[2];
        s3 = t[3];
    }
}
