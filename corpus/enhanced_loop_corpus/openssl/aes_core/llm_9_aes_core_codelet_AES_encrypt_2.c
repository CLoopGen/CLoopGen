#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern  u32 Te0[256];
extern  u32 Te1[256];
extern  u32 Te2[256];
extern  u32 Te3[256];
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
    for (int trip = 0; trip < (r > 8 ? 8 : r); ++trip) {
        // Unroll the original loop body twice to increase computational density
        t0 = Te0[(s0 >> 24)] ^ Te1[(s1 >> 16) & 255] ^ Te2[(s2 >> 8) & 255] ^ Te3[(s3) & 255] ^ rk[4];
        t1 = Te0[(s1 >> 24)] ^ Te1[(s2 >> 16) & 255] ^ Te2[(s3 >> 8) & 255] ^ Te3[(s0) & 255] ^ rk[5];
        t2 = Te0[(s2 >> 24)] ^ Te1[(s3 >> 16) & 255] ^ Te2[(s0 >> 8) & 255] ^ Te3[(s1) & 255] ^ rk[6];
        t3 = Te0[(s3 >> 24)] ^ Te1[(s0 >> 16) & 255] ^ Te2[(s1 >> 8) & 255] ^ Te3[(s2) & 255] ^ rk[7];
        rk += 8;

        if (--r == 0) break;

        s0 = Te0[(t0 >> 24)] ^ Te1[(t1 >> 16) & 255] ^ Te2[(t2 >> 8) & 255] ^ Te3[(t3) & 255] ^ rk[0];
        s1 = Te0[(t1 >> 24)] ^ Te1[(t2 >> 16) & 255] ^ Te2[(t3 >> 8) & 255] ^ Te3[(t0) & 255] ^ rk[1];
        s2 = Te0[(t2 >> 24)] ^ Te1[(t3 >> 16) & 255] ^ Te2[(t0 >> 8) & 255] ^ Te3[(t1) & 255] ^ rk[2];
        s3 = Te0[(t3 >> 24)] ^ Te1[(t0 >> 16) & 255] ^ Te2[(t1 >> 8) & 255] ^ Te3[(t2) & 255] ^ rk[3];

        // Second iteration of original loop logic, without exit check in middle
        t0 = Te0[(s0 >> 24)] ^ Te1[(s1 >> 16) & 255] ^ Te2[(s2 >> 8) & 255] ^ Te3[(s3) & 255] ^ rk[4];
        t1 = Te0[(s1 >> 24)] ^ Te1[(s2 >> 16) & 255] ^ Te2[(s3 >> 8) & 255] ^ Te3[(s0) & 255] ^ rk[5];
        t2 = Te0[(s2 >> 24)] ^ Te1[(s3 >> 16) & 255] ^ Te2[(s0 >> 8) & 255] ^ Te3[(s1) & 255] ^ rk[6];
        t3 = Te0[(s3 >> 24)] ^ Te1[(s0 >> 16) & 255] ^ Te2[(s1 >> 8) & 255] ^ Te3[(s2) & 255] ^ rk[7];
        rk += 8;

        if (--r == 0) break;

        s0 = Te0[(t0 >> 24)] ^ Te1[(t1 >> 16) & 255] ^ Te2[(t2 >> 8) & 255] ^ Te3[(t3) & 255] ^ rk[0];
        s1 = Te0[(t1 >> 24)] ^ Te1[(t2 >> 16) & 255] ^ Te2[(t3 >> 8) & 255] ^ Te3[(t0) & 255] ^ rk[1];
        s2 = Te0[(t2 >> 24)] ^ Te1[(t3 >> 16) & 255] ^ Te2[(t0 >> 8) & 255] ^ Te3[(t1) & 255] ^ rk[2];
        s3 = Te0[(t3 >> 24)] ^ Te1[(t0 >> 16) & 255] ^ Te2[(t1 >> 8) & 255] ^ Te3[(t2) & 255] ^ rk[3];
    }
}
