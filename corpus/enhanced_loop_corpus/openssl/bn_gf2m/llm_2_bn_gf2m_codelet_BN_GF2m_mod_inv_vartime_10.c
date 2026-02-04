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



void loop() {
    // Variant 1: Strided Memory Access (step of 2, unrolled-like pattern)
    // Access elements with stride 2 to change memory access pattern
    // Loop adjusted to avoid out-of-bounds for strided access
    int limit = (top - 1) / 2;
    for (i = 0; i < limit; i++) {
        int idx = 2 * i;  // Stride of 2
        u1 = udp[idx + 1];
        udp[idx] = ((u0 >> 1) | (u1 << 63)) & 0xFFFFFFFFFFFFFFFFUL;
        u0 = u1;

        b1 = bdp[idx + 1] ^ (p->d[idx + 1] & mask);
        bdp[idx] = ((b0 >> 1) | (b1 << 63)) & 0xFFFFFFFFFFFFFFFFUL;
        b0 = b1;
    }
}
