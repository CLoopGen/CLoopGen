#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern  BIGNUM *p;
extern int i;
extern int top;
extern unsigned long *udp;
extern unsigned long *bdp;
extern unsigned long u0;
extern unsigned long u1;
extern unsigned long b0;
extern unsigned long b1;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < top - 2; i += 2) {
        u1 = udp[i + 1];
        u0 = ((u0 >> 1) | (u1 << 63)) & 18446744073709551615UL;
        udp[i] = u0;
        
        if (i + 2 < top - 1) {
            unsigned long u2 = udp[i + 2];
            udp[i + 1] = ((u1 >> 1) | (u2 << 63)) & 18446744073709551615UL;
        }

        b1 = bdp[i + 1] ^ (p->d[i + 1] & mask);
        b0 = ((b0 >> 1) | (b1 << 63)) & 18446744073709551615UL;
        bdp[i] = b0;

        if (i + 2 < top - 1) {
            unsigned long b2 = bdp[i + 2] ^ (p->d[i + 2] & mask);
            bdp[i + 1] = ((b1 >> 1) | (b2 << 63)) & 18446744073709551615UL;
        }
    }
}
