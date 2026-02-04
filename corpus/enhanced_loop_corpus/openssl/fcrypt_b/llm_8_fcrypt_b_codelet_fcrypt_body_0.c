#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern const DES_LONG DES_SPtrans[8][64];
extern DES_LONG l;
extern DES_LONG r;
extern DES_LONG t;
extern DES_LONG u;
extern DES_LONG *s;
extern int j;
extern DES_LONG E0;
extern DES_LONG E1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 50; j++) {
    {
        DES_LONG tmp;
        t = r ^ (r >> 16L);
        u = t & E0;
        t &= E1;
        tmp = (u << 16);
        u ^= r ^ s[0];
        u ^= tmp;
        tmp = (t << 16);
        t ^= r ^ s[1];
        t ^= tmp;
        t = ({
            register unsigned int ret;
            asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t) : "cc");
            ret;
        });
        l ^= DES_SPtrans[0][(u >> 2L) & 63] ^ DES_SPtrans[2][(u >> 10L) & 63] ^ DES_SPtrans[4][(u >> 18L) & 63] ^ DES_SPtrans[6][(u >> 26L) & 63] ^ DES_SPtrans[1][(t >> 2L) & 63] ^ DES_SPtrans[3][(t >> 10L) & 63] ^ DES_SPtrans[5][(t >> 18L) & 63] ^ DES_SPtrans[7][(t >> 26L) & 63];
    }
    ;
    {
        DES_LONG tmp;
        t = l ^ (l >> 16L);
        u = t & E0;
        t &= E1;
        tmp = (u << 16);
        u ^= l ^ s[2];
        u ^= tmp;
        tmp = (t << 16);
        t ^= l ^ s[3];
        t ^= tmp;
        t = ({
            register unsigned int ret;
            asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t) : "cc");
            ret;
        });
        r ^= DES_SPtrans[0][(u >> 2L) & 63] ^ DES_SPtrans[2][(u >> 10L) & 63] ^ DES_SPtrans[4][(u >> 18L) & 63] ^ DES_SPtrans[6][(u >> 26L) & 63] ^ DES_SPtrans[1][(t >> 2L) & 63] ^ DES_SPtrans[3][(t >> 10L) & 63] ^ DES_SPtrans[5][(t >> 18L) & 63] ^ DES_SPtrans[7][(t >> 26L) & 63];
    }
    ;
    t = l;
    l = r;
    r = t;
}
}
