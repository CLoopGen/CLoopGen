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
u32 prev_t0 = t[0]; 
for (i = 0; i < 4; i++) {
    r0 = t[i];
    r1 = r0 & 2155905152U;
    r2 = ((r0 & 2139062143) << 1) ^ ((r1 - (r1 >> 7)) & 454761243);
    t[i] = r2 ^ ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r2) : "cc");
        ret;
    }) ^ ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r0) : "cc");
        ret;
    }) ^ ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (16), "0" (r0) : "cc");
        ret;
    }) ^ ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (8), "0" (r0) : "cc");
        ret;
    });
    t[i] ^= rk[4 + i];
    if (i > 0) {
        t[i] ^= prev_t0;  
    }
    prev_t0 = t[i];  
}
}
