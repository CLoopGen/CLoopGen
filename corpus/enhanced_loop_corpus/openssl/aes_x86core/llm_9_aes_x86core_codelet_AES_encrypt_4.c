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
for (i = 0; i < 2; i++) {
    r0 = t[i * 2];
    r1 = r0 & 2155905152U;
    r2 = ((r0 & 2139062143) << 1) ^ ((r1 - (r1 >> 7)) & 454761243);
    u32 temp1 = ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r2) : "cc");
        ret;
    });
    u32 temp2 = ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r0) : "cc");
        ret;
    });
    u32 temp3 = ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (16), "0" (r0) : "cc");
        ret;
    });
    u32 temp4 = ({
        register unsigned int ret;
        asm ("roll %1,%0" : "=r" (ret) : "I" (8), "0" (r0) : "cc");
        ret;
    });
    t[i * 2] = r2 ^ temp1 ^ temp2 ^ temp3 ^ temp4;
    if (i * 2 + 1 < 4) {
        r0 = t[i * 2 + 1];
        r1 = r0 & 2155905152U;
        r2 = ((r0 & 2139062143) << 1) ^ ((r1 - (r1 >> 7)) & 454761243);
        u32 next_temp1 = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r2) : "cc");
            ret;
        });
        u32 next_temp2 = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (r0) : "cc");
            ret;
        });
        u32 next_temp3 = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (16), "0" (r0) : "cc");
            ret;
        });
        u32 next_temp4 = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (8), "0" (r0) : "cc");
            ret;
        });
        t[i * 2 + 1] = r2 ^ next_temp1 ^ next_temp2 ^ next_temp3 ^ next_temp4;
        t[i * 2 + 1] ^= rk[4 + i * 2 + 1];
    }
    t[i * 2] ^= rk[4 + i * 2];
}
}
