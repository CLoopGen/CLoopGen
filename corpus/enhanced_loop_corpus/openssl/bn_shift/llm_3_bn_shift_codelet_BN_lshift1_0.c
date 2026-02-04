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
    // Variant 2: Strided memory access (process every 2nd element in two passes: even then odd indices)
    // First pass: even indices
    for (i = 0; i < a->top; i += 2) {
        t = ap[i];
        rp[i] = ((t << 1) | c) & (18446744073709551615UL);
        c = t >> ((8 * 8) - 1);
    }
    // Second pass: odd indices, reusing same logic with offset
    for (i = 1; i < a->top; i += 2) {
        t = ap[i];
        rp[i] = ((t << 1) | c) & (18446744073709551615UL);
        c = t >> ((8 * 8) - 1);
    }
}
