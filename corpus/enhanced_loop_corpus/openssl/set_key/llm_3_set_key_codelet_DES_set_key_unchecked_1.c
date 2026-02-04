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
DES_LONG *skb_ptr = &des_skb[0][0];
for (i = 0; i < 16; i++) {
    if (shifts2[i]) {
        c = ((c >> 2L) | (c << 26L));
        d = ((d >> 2L) | (d << 26L));
    } else {
        c = ((c >> 1L) | (c << 27L));
        d = ((d >> 1L) | (d << 27L));
    }
    c &= 268435455L;
    d &= 268435455L;
    s = skb_ptr[(c) & 63] |
        skb_ptr[64 + (((c >> 6L) & 3) | ((c >> 7L) & 60))] |
        skb_ptr[128 + (((c >> 13L) & 15) | ((c >> 14L) & 48))] |
        skb_ptr[192 + (((c >> 20L) & 1) | ((c >> 21L) & 6) | ((c >> 22L) & 56))];
    t = skb_ptr[256 + (d & 63)] |
        skb_ptr[320 + (((d >> 7L) & 3) | ((d >> 8L) & 60))] |
        skb_ptr[384 + ((d >> 15L) & 63)] |
        skb_ptr[448 + (((d >> 21L) & 15) | ((d >> 22L) & 48))];
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
