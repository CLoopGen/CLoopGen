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
    for (i = 0; i < 4; i++) {
        r0 = t[i];
        r1 = r0 & 2155905152U;
        r2 = ((r0 & 2139062143) << 1) ^ ((r1 - (r1 >> 7)) & 454761243);
        u32 rolled_r2, rolled_r0_24, rolled_r0_16, rolled_r0_8;

        asm ("roll %1,%0" : "=r" (rolled_r2) : "I" (24), "0" (r2) : "cc");
        asm ("roll %1,%0" : "=r" (rolled_r0_24) : "I" (24), "0" (r0) : "cc");
        asm ("roll %1,%0" : "=r" (rolled_r0_16) : "I" (16), "0" (r0) : "cc");
        asm ("roll %1,%0" : "=r" (rolled_r0_8) : "I" (8), "0" (r0) : "cc");

        t[i] = r2 ^ rolled_r2 ^ rolled_r0_24 ^ rolled_r0_16 ^ rolled_r0_8;
        if (r2 != 0) {
            t[i] ^= rk[4 + i];
        }
    }
}
