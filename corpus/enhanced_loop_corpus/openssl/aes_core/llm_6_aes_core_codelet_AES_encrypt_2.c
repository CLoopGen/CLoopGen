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
for (;;) {
    u32 temp0 = Te0[(s0 >> 24)];
    u32 temp1 = Te1[(s1 >> 16) & 255];
    u32 temp2 = Te2[(s2 >> 8) & 255];
    u32 temp3 = Te3[(s3) & 255];
    t0 = temp0 ^ temp1 ^ temp2 ^ temp3 ^ rk[4];

    temp0 = Te0[(s1 >> 24)];
    temp1 = Te1[(s2 >> 16) & 255];
    temp2 = Te2[(s3 >> 8) & 255];
    temp3 = Te3[(s0) & 255];
    t1 = temp0 ^ temp1 ^ temp2 ^ temp3 ^ rk[5];

    temp0 = Te0[(s2 >> 24)];
    temp1 = Te1[(s3 >> 16) & 255];
    temp2 = Te2[(s0 >> 8) & 255];
    temp3 = Te3[(s1) & 255];
    t2 = temp0 ^ temp1 ^ temp2 ^ temp3 ^ rk[6];

    temp0 = Te0[(s3 >> 24)];
    temp1 = Te1[(s0 >> 16) & 255];
    temp2 = Te2[(s1 >> 8) & 255];
    temp3 = Te3[(s2) & 255];
    t3 = temp0 ^ temp1 ^ temp2 ^ temp3 ^ rk[7];

    rk += 8;
    if (--r == 0) {
        break;
    }

    s0 = Te0[(t0 >> 24)] ^ Te1[(t1 >> 16) & 255] ^ Te2[(t2 >> 8) & 255] ^ Te3[(t3) & 255] ^ rk[0];
    s1 = Te0[(t1 >> 24)] ^ Te1[(t2 >> 16) & 255] ^ Te2[(t3 >> 8) & 255] ^ Te3[(t0) & 255] ^ rk[1];
    s2 = Te0[(t2 >> 24)] ^ Te1[(t3 >> 16) & 255] ^ Te2[(t0 >> 8) & 255] ^ Te3[(t1) & 255] ^ rk[2];
    s3 = Te0[(t3 >> 24)] ^ Te1[(t0 >> 16) & 255] ^ Te2[(t1 >> 8) & 255] ^ Te3[(t2) & 255] ^ rk[3];
}
}
