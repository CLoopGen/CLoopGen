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
    u32 indices[8];
    for (int i = 0; i < r && (--r + 1); ) {
        indices[0] = (s0 >> 24);       indices[1] = (s3 >> 16) & 255;
        indices[2] = (s2 >> 8) & 255;  indices[3] = s1 & 255;
        indices[4] = (s1 >> 24);       indices[5] = (s0 >> 16) & 255;
        indices[6] = (s3 >> 8) & 255;  indices[7] = s2 & 255;

        t0 = Td0[indices[0]] ^ Td1[indices[1]] ^ Td2[indices[2]] ^ Td3[indices[3]] ^ rk[4];
        t1 = Td0[indices[4]] ^ Td1[indices[5]] ^ Td2[indices[6]] ^ Td3[indices[7]] ^ rk[5];

        indices[0] = (s2 >> 24);       indices[1] = (s1 >> 16) & 255;
        indices[2] = (s0 >> 8) & 255;  indices[3] = s3 & 255;
        indices[4] = (s3 >> 24);       indices[5] = (s2 >> 16) & 255;
        indices[6] = (s1 >> 8) & 255;  indices[7] = s0 & 255;

        t2 = Td0[indices[0]] ^ Td1[indices[1]] ^ Td2[indices[2]] ^ Td3[indices[3]] ^ rk[6];
        t3 = Td0[indices[4]] ^ Td1[indices[5]] ^ Td2[indices[6]] ^ Td3[indices[7]] ^ rk[7];

        rk += 8;
        i++;
        if (i >= r + 1) break;

        indices[0] = (t0 >> 24);       indices[1] = (t3 >> 16) & 255;
        indices[2] = (t2 >> 8) & 255;   indices[3] = t1 & 255;
        indices[4] = (t1 >> 24);       indices[5] = (t0 >> 16) & 255;
        indices[6] = (t3 >> 8) & 255;  indices[7] = t2 & 255;

        s0 = Td0[indices[0]] ^ Td1[indices[1]] ^ Td2[indices[2]] ^ Td3[indices[3]] ^ rk[0];
        s1 = Td0[indices[4]] ^ Td1[indices[5]] ^ Td2[indices[6]] ^ Td3[indices[7]] ^ rk[1];

        indices[0] = (t2 >> 24);       indices[1] = (t1 >> 16) & 255;
        indices[2] = (t0 >> 8) & 255;  indices[3] = t3 & 255;
        indices[4] = (t3 >> 24);       indices[5] = (t2 >> 16) & 255;
        indices[6] = (t1 >> 8) & 255;  indices[7] = t0 & 255;

        s2 = Td0[indices[0]] ^ Td1[indices[1]] ^ Td2[indices[2]] ^ Td3[indices[3]] ^ rk[2];
        s3 = Td0[indices[4]] ^ Td1[indices[5]] ^ Td2[indices[6]] ^ Td3[indices[7]] ^ rk[3];
    }
}
