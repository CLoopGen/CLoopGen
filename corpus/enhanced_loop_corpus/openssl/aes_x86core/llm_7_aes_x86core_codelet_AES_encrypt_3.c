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

extern  u64 Te[256];
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
u32 temp_s0 = s0, temp_s1 = s1, temp_s2 = s2, temp_s3 = s3;
for (rk += 8 , r = key->rounds - 2; r > 0; rk += 4 , r--) {
    u32 new_t0 = (u32)((u64 *)((u8 *)Te + 0))[temp_s0 & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 3))[(temp_s1 >> 8) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 2))[(temp_s2 >> 16) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 1))[(temp_s3 >> 24)] ^ rk[0];
    u32 new_t1 = (u32)((u64 *)((u8 *)Te + 0))[temp_s1 & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 3))[(temp_s2 >> 8) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 2))[(temp_s3 >> 16) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 1))[(temp_s0 >> 24)] ^ rk[1];
    u32 new_t2 = (u32)((u64 *)((u8 *)Te + 0))[temp_s2 & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 3))[(temp_s3 >> 8) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 2))[(temp_s0 >> 16) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 1))[(temp_s1 >> 24)] ^ rk[2];
    u32 new_t3 = (u32)((u64 *)((u8 *)Te + 0))[temp_s3 & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 3))[(temp_s0 >> 8) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 2))[(temp_s1 >> 16) & 255] ^ 
                 (u32)((u64 *)((u8 *)Te + 1))[(temp_s2 >> 24)] ^ rk[3];
    temp_s0 = new_t0;
    temp_s1 = new_t1;
    temp_s2 = new_t2;
    temp_s3 = new_t3;
}
s0 = temp_s0; s1 = temp_s1; s2 = temp_s2; s3 = temp_s3;
}
