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
    rk += 8;
    r = key->rounds - 2;
    for (; r > 0; ) {
        if (r % 2 == 0) {
            t[0] = (u32)((u64 *)((u8 *)Te + 0))[(s0) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s1 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s2 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s3 >> 24)] ^ rk[0];
            t[1] = (u32)((u64 *)((u8 *)Te + 0))[(s1) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s2 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s3 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s0 >> 24)] ^ rk[1];
            t[2] = (u32)((u64 *)((u8 *)Te + 0))[(s2) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s3 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s0 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s1 >> 24)] ^ rk[2];
            t[3] = (u32)((u64 *)((u8 *)Te + 0))[(s3) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s0 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s1 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s2 >> 24)] ^ rk[3];
        } else {
            u32 temp0 = (u32)((u64 *)((u8 *)Te + 0))[(s0) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s1 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s2 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s3 >> 24)] ^ rk[0];
            u32 temp1 = (u32)((u64 *)((u8 *)Te + 0))[(s1) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s2 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s3 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s0 >> 24)] ^ rk[1];
            u32 temp2 = (u32)((u64 *)((u8 *)Te + 0))[(s2) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s3 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s0 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s1 >> 24)] ^ rk[2];
            u32 temp3 = (u32)((u64 *)((u8 *)Te + 0))[(s3) & 255] ^ (u32)((u64 *)((u8 *)Te + 3))[(s0 >> 8) & 255] ^ (u32)((u64 *)((u8 *)Te + 2))[(s1 >> 16) & 255] ^ (u32)((u64 *)((u8 *)Te + 1))[(s2 >> 24)] ^ rk[3];
            t[0] = temp0; t[1] = temp1; t[2] = temp2; t[3] = temp3;
        }
        s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
        rk += 4;
        r--;
    }
}
