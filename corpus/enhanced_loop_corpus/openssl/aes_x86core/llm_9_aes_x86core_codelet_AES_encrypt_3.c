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
int step = 2;
for (rk += 8, r = (key->rounds - 2) / step; r > 0; rk += 8, r -= 1) {
    u32 t0_0, t0_1, t0_2, t0_3;
    u32 t1_0, t1_1, t1_2, t1_3;

    t0_0 = (u32)((u64 *)((u8 *)Te + 0))[(s0) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s1 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s2 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s3 >> 24)] ^ rk[0];
    t0_1 = (u32)((u64 *)((u8 *)Te + 0))[(s1) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s2 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s3 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s0 >> 24)] ^ rk[1];
    t0_2 = (u32)((u64 *)((u8 *)Te + 0))[(s2) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s3 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s0 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s1 >> 24)] ^ rk[2];
    t0_3 = (u32)((u64 *)((u8 *)Te + 0))[(s3) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s0 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s1 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s2 >> 24)] ^ rk[3];

    t1_0 = (u32)((u64 *)((u8 *)Te + 0))[(t0_0) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(t0_1 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(t0_2 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(t0_3 >> 24)] ^ rk[4];
    t1_1 = (u32)((u64 *)((u8 *)Te + 0))[(t0_1) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(t0_2 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(t0_3 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(t0_0 >> 24)] ^ rk[5];
    t1_2 = (u32)((u64 *)((u8 *)Te + 0))[(t0_2) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(t0_3 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(t0_0 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(t0_1 >> 24)] ^ rk[6];
    t1_3 = (u32)((u64 *)((u8 *)Te + 0))[(t0_3) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(t0_0 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(t0_1 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(t0_2 >> 24)] ^ rk[7];

    s0 = t1_0;
    s1 = t1_1;
    s2 = t1_2;
    s3 = t1_3;
}
}
