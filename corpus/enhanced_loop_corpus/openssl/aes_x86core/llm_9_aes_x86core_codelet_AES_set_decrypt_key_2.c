#include <stdio.h>

#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

extern AES_KEY *key;
extern u32 *rk;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < (key->rounds + (key->rounds > 10 ? 2 : 0)); i += (key->rounds > 10 ? 1 : 1)) {
    rk += 4;
    u32 local_accum = 0;
    for (j = 0; j < 4; j++) {
        u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
        tp1 = rk[j] ^ local_accum;
        m = tp1 & 2155905152U;
        tp2 = ((tp1 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp2 & 2155905152U;
        tp4 = ((tp2 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp4 & 2155905152U;
        tp8 = ((tp4 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        tp9 = tp8 ^ tp1;
        tpb = tp9 ^ tp2;
        tpd = tp9 ^ tp4;
        tpe = tp8 ^ tp4 ^ tp2;
        u32 rolled_pdb = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (16), "0" (tpd) : "cc");
            ret;
        });
        u32 rolled_9 = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (8), "0" (tp9) : "cc");
            ret;
        });
        u32 rolled_b = ({
            register unsigned int ret;
            asm ("roll %1,%0" : "=r" (ret) : "I" (24), "0" (tpb) : "cc");
            ret;
        });
        rk[j] = tpe ^ rolled_pdb ^ rolled_9 ^ rolled_b;
        local_accum ^= rk[j];
    }
}
}
