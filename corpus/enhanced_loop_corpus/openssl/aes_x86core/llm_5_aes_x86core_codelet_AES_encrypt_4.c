#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern  u32 *rk;
extern u32 t[4];
extern int i;
extern u32 r0;
extern u32 r1;
extern u32 r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        if (i % 2 == 0) {
            r0 = t[i];
            r1 = r0 & 2155905152U;
            r2 = ((r0 & 2139062143) << 1) ^ ((r1 - (r1 >> 7)) & 454761243);
        } else {
            r0 = t[i] ^ rk[i]; 
            r2 = (r0 << 1) ^ (r0 >> 31);
        }

        u32 temp;
        asm ("roll %1,%0" : "=r" (temp) : "I" (24), "0" (r2) : "cc");
        t[i] = r2 ^ temp;

        asm ("roll %1,%0" : "+r" (r0) : "I" (24) : "cc");
        t[i] ^= r0;
        asm ("roll %1,%0" : "+r" (r0) : "I" (16) : "cc");
        t[i] ^= r0;
        asm ("roll %1,%0" : "+r" (r0) : "I" (8) : "cc");
        t[i] ^= r0;

        if (i >= 0) {
            t[i] ^= rk[4 + i];
        }
    }
}
