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
    rk += 8;
    r = (key->rounds - 2) / 2;  // Reduced trip count: half the original iterations
    for (; r > 0; rk += 8, r--) {  // Increment rk by 8 to maintain alignment with two rounds per iteration
        // First round computation
        t[0] = (u32)((u64 *)((u8 *)Td + 0))[(s0) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(s3 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(s2 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(s1 >> 24)] ^ rk[0];
        t[1] = (u32)((u64 *)((u8 *)Td + 0))[(s1) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(s0 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(s3 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(s2 >> 24)] ^ rk[1];
        t[2] = (u32)((u64 *)((u8 *)Td + 0))[(s2) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(s1 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(s0 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(s3 >> 24)] ^ rk[2];
        t[3] = (u32)((u64 *)((u8 *)Td + 0))[(s3) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(s2 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(s1 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(s0 >> 24)] ^ rk[3];

        u32 temp_s0 = t[0], temp_s1 = t[1], temp_s2 = t[2], temp_s3 = t[3];

        // Second round computation using updated state
        t[0] = (u32)((u64 *)((u8 *)Td + 0))[(temp_s0) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(temp_s3 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(temp_s2 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(temp_s1 >> 24)] ^ rk[4];
        t[1] = (u32)((u64 *)((u8 *)Td + 0))[(temp_s1) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(temp_s0 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(temp_s3 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(temp_s2 >> 24)] ^ rk[5];
        t[2] = (u32)((u64 *)((u8 *)Td + 0))[(temp_s2) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(temp_s1 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(temp_s0 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(temp_s3 >> 24)] ^ rk[6];
        t[3] = (u32)((u64 *)((u8 *)Td + 0))[(temp_s3) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 3))[(temp_s2 >> 8) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 2))[(temp_s1 >> 16) & 255] ^ 
               (u32)((u64 *)((u8 *)Td + 1))[(temp_s0 >> 24)] ^ rk[7];

        s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
    }
}
