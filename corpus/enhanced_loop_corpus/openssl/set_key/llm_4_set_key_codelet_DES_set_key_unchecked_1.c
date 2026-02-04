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
const int index_map[8][4] = {
    {0, 64, 128, 192},
    {0, 64, 128, 192},
    {256, 320, 384, 448},
    {256, 320, 384, 448},
    {256, 320, 384, 448},
    {256, 320, 384, 448},
    {256, 320, 384, 448},
    {256, 320, 384, 448}
};
int j;
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
    s = 0;
    j = (c) & 63; s |= des_skb[index_map[0][0]/64][j];
    j = ((c >> 6L) & 3) | ((c >> 7L) & 60); s |= des_skb[index_map[1][1]/64][j];
    j = ((c >> 13L) & 15) | ((c >> 14L) & 48); s |= des_skb[index_map[2][2]/64][j];
    j = ((c >> 20L) & 1) | ((c >> 21L) & 6) | ((c >> 22L) & 56); s |= des_skb[index_map[3][3]/64][j];
    t = 0;
    j = (d) & 63; t |= des_skb[index_map[4][0]/64][j];
    j = ((d >> 7L) & 3) | ((d >> 8L) & 60); t |= des_skb[index_map[5][1]/64][j];
    j = (d >> 15L) & 63; t |= des_skb[index_map[6][2]/64][j];
    j = ((d >> 21L) & 15) | ((d >> 22L) & 48); t |= des_skb[index_map[7][3]/64][j];
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
