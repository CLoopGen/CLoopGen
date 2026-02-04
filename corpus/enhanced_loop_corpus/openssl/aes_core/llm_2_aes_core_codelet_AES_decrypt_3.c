#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern  u32 Td0[256];
extern  u32 Td1[256];
extern  u32 Td2[256];
extern  u32 Td3[256];
extern  u32 *rk;
extern u32 s0;
extern u32 s1;
extern u32 s2;
extern u32 s3;
extern u32 t0;
extern u32 t1;
extern u32 t2;
extern u32 t3;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < r; i++) {
        t0 = Td0[(s0 >> 24)] ^ Td1[(s3 >> 16) & 255] ^ Td2[(s2 >> 8) & 255] ^ Td3[(s1) & 255] ^ rk[4];
        t1 = Td0[(s1 >> 24)] ^ Td1[(s0 >> 16) & 255] ^ Td2[(s3 >> 8) & 255] ^ Td3[(s2) & 255] ^ rk[5];
        t2 = Td0[(s2 >> 24)] ^ Td1[(s1 >> 16) & 255] ^ Td2[(s0 >> 8) & 255] ^ Td3[(s3) & 255] ^ rk[6];
        t3 = Td0[(s3 >> 24)] ^ Td1[(s2 >> 16) & 255] ^ Td2[(s1 >> 8) & 255] ^ Td3[(s0) & 255] ^ rk[7];
        rk += 8;
        if (i == r - 1) break;
        s0 = Td0[(t0 >> 24)] ^ Td1[(t3 >> 16) & 255] ^ Td2[(t2 >> 8) & 255] ^ Td3[(t1) & 255] ^ rk[0];
        s1 = Td0[(t1 >> 24)] ^ Td1[(t0 >> 16) & 255] ^ Td2[(t3 >> 8) & 255] ^ Td3[(t2) & 255] ^ rk[1];
        s2 = Td0[(t2 >> 24)] ^ Td1[(t1 >> 16) & 255] ^ Td2[(t0 >> 8) & 255] ^ Td3[(t3) & 255] ^ rk[2];
        s3 = Td0[(t3 >> 24)] ^ Td1[(t2 >> 16) & 255] ^ Td2[(t1 >> 8) & 255] ^ Td3[(t0) & 255] ^ rk[3];
    }
}
