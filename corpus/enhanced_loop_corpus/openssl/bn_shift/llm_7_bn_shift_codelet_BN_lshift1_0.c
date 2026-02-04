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
    unsigned long local_c = c;
    for (i = 0; i < a->top; i++) {
        t = *(ap++);
        *(rp++) = ((t << 1) | local_c) & (18446744073709551615UL);
        local_c = t >> 63;
    }
    c = local_c;
}
