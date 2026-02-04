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

extern  BIGNUM *a;
extern unsigned long *ap;
extern unsigned long *rp;
extern unsigned long t;
extern unsigned long c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal (backward iteration)
    for (i = a->top - 1; i >= 0; i--) {
        t = ap[i];
        rp[i] = ((t << 1) | c) & (18446744073709551615UL);
        c = t >> ((8 * 8) - 1);
    }
}
