#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern  DES_LONG des_skb[8][64];
extern  int shifts2[16];
extern DES_LONG c;
extern DES_LONG d;
extern DES_LONG t;
extern DES_LONG s;
extern DES_LONG t2;
extern DES_LONG *k;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
DES_LONG c_local = c;
DES_LONG d_local = d;
for (i = 0; i < 16; i++) {
    if (shifts2[i]) {
        c_local = ((c_local >> 2L) | (c_local << 26L));
        d_local = ((d_local >> 2L) | (d_local << 26L));
    } else {
        c_local = ((c_local >> 1L) | (c_local << 27L));
        d_local = ((d_local >> 1L) | (d_local << 27L));
    }
    c_local &= 268435455L;
    d_local &= 268435455L;
    s = des_skb[0][(c_local) & 63] | des_skb[1][((c_local >> 6L) & 3) | ((c_local >> 7L) & 60)] | des_skb[2][((c_local >> 13L) & 15) | ((c_local >> 14L) & 48)] | des_skb[3][((c_local >> 20L) & 1) | ((c_local >> 21L) & 6) | ((c_local >> 22L) & 56)];
    t = des_skb[4][(d_local) & 63] | des_skb[5][((d_local >> 7L) & 3) | ((d_local >> 8L) & 60)] | des_skb[6][(d_local >> 15L) & 63] | des_skb[7][((d_local >> 21L) & 15) | ((d_local >> 22L) & 48)];
    t2 = ((t << 16L) | (s & 65535L)) & 4294967295L;
    *(k++) = ({
        register unsigned int ret;
        asm ("rorl %1,%0" : "=r" (ret) : "I" (30), "0" (t2) : "cc");
        ret;
    }) & 4294967295L;
    t2 = ((s >> 16L) | (t & 4294901760L));
    *(k++) = ({
        register unsigned int ret;
        asm ("rorl %1,%0" : "=r" (ret) : "I" (26), "0" (t2) : "cc");
        ret;
    }) & 4294967295L;
}
c = c_local;
d = d_local;
}
