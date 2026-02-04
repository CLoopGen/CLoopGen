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
for (i = 0; i < 16; i++) {
    if (shifts2[i]) {
        c = ((c >> 2L) | (c << 26L));
        d = ((d >> 2L) | (d << 26L));
    } else if (i & 1) {
        c = ((c >> 3L) | (c << 25L));
        d = ((d >> 3L) | (d << 25L));
    } else {
        c = ((c >> 1L) | (c << 27L));
        d = ((d >> 1L) | (d << 27L));
    }
    c &= 268435455L;
    d &= 268435455L;
    s = des_skb[0][(c) & 63] | des_skb[1][((c >> 6L) & 3) | ((c >> 7L) & 60)] | des_skb[2][((c >> 13L) & 15) | ((c >> 14L) & 48)] | des_skb[3][((c >> 20L) & 1) | ((c >> 21L) & 6) | ((c >> 22L) & 56)];
    t = des_skb[4][(d) & 63] | des_skb[5][((d >> 7L) & 3) | ((d >> 8L) & 60)] | des_skb[6][(d >> 15L) & 63] | des_skb[7][((d >> 21L) & 15) | ((d >> 22L) & 48)];
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
}
