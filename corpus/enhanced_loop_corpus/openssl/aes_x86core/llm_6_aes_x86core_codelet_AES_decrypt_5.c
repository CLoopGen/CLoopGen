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
for (rk += 8 , r = key->rounds - 2; r > 0; rk += 4 , r--) {
    u32 t0 = (u32)((u64 *)((u8 *)Td + 0))[(s0) & 255] ^ (u32)((u64 *)((u8 *)Td + 3))[(s3 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Td + 2))[(s2 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Td + 1))[(s1 >> 24)] ^ rk[0];
    u32 t1 = (u32)((u64 *)((u8 *)Td + 0))[(s1) & 255] ^ (u32)((u64 *)((u8 *)Td + 3))[(s0 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Td + 2))[(s3 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Td + 1))[(s2 >> 24)] ^ rk[1];
    u32 t2 = (u32)((u64 *)((u8 *)Td + 0))[(s2) & 255] ^ (u32)((u64 *)((u8 *)Td + 3))[(s1 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Td + 2))[(s0 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Td + 1))[(s3 >> 24)] ^ rk[2];
    u32 t3 = (u32)((u64 *)((u8 *)Td + 0))[(s3) & 255] ^ (u32)((u64 *)((u8 *)Td + 3))[(s2 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Td + 2))[(s1 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Td + 1))[(s0 >> 24)] ^ rk[3];
    s0 = t0;
    s1 = t1;
    s2 = t2;
    s3 = t3;
}
}
