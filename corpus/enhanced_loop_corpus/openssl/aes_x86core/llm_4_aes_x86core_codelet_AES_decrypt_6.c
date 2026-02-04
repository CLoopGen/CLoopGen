#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern  u32 *rk;
extern u32 t[4];
extern int i;
extern u32 tp1;
extern u32 tp2;
extern u32 tp4;
extern u32 tp8;
extern u32 tp9;
extern u32 tpb;
extern u32 tpd;
extern u32 tpe;
extern u32 m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    tp1 = t[i];
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

    u32 rolled_tpd, rolled_tp9, rolled_tpb;
    asm ("roll %1,%0" : "=r" (rolled_tpd) : "I" (16), "0" (tpd) : "cc");
    asm ("roll %1,%0" : "=r" (rolled_tp9) : "I" (8), "0" (tp9) : "cc");
    asm ("roll %1,%0" : "=r" (rolled_tpb) : "I" (24), "0" (tpb) : "cc");

    t[i] = tpe ^ rolled_tpd ^ rolled_tp9 ^ rolled_tpb;
    t[i] ^= rk[4 + i];
}
}
