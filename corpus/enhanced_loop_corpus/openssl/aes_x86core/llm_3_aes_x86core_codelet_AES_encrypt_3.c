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
    const int stride = 256;
    u64 *te0 = (u64 *)((u8 *)Te + 0);
    u64 *te1 = (u64 *)((u8 *)Te + 8);
    u64 *te2 = (u64 *)((u8 *)Te + 16);
    u64 *te3 = (u64 *)((u8 *)Te + 24);
    for (; r > 0; rk += 4, r--) {
        t[0] = (u32)te0[s0 & 255] ^ (u32)te3[(s1 >> 8) & 255] ^ (u32)te2[(s2 >> 16) & 255] ^ (u32)te1[(s3 >> 24)] ^ rk[0];
        t[1] = (u32)te0[s1 & 255] ^ (u32)te3[(s2 >> 8) & 255] ^ (u32)te2[(s3 >> 16) & 255] ^ (u32)te1[(s0 >> 24)] ^ rk[1];
        t[2] = (u32)te0[s2 & 255] ^ (u32)te3[(s3 >> 8) & 255] ^ (u32)te2[(s0 >> 16) & 255] ^ (u32)te1[(s1 >> 24)] ^ rk[2];
        t[3] = (u32)te0[s3 & 255] ^ (u32)te3[(s0 >> 8) & 255] ^ (u32)te2[(s1 >> 16) & 255] ^ (u32)te1[(s2 >> 24)] ^ rk[3];
        s0 = t[0];
        s1 = t[1];
        s2 = t[2];
        s3 = t[3];
    }
}
