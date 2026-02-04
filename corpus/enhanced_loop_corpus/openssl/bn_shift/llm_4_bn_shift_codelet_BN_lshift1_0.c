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
    for (i = 0; i < a->top; i++) {
        t = *(ap++);
        if (t != 0) {
            *(rp++) = ((t << 1) | c) & (18446744073709551615UL);
            c = t >> 63;
        } else {
            *(rp++) = c;
            c = 0;
        }
    }
}
