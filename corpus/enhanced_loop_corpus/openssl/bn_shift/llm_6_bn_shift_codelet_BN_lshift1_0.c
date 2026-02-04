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
    unsigned long temp;
    for (i = 0; i < a->top; i++) {
        temp = ap[i];
        rp[i] = ((temp << 1) | c) & (18446744073709551615UL);
        c = temp >> 63;
    }
}
