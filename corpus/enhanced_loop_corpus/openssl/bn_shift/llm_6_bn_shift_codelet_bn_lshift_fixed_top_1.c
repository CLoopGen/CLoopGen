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
extern int i;
extern unsigned int lb;
extern unsigned int rb;
extern unsigned long *t;
extern unsigned long *f;
extern unsigned long l;
extern unsigned long m;
extern unsigned long rmask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long prev_l = f[a->top - 2];
    for (i = a->top - 1; i > 0; i--) {
        m = prev_l << lb;
        prev_l = f[i - 1];
        t[i] = (m | ((f[i - 1] >> rb) & rmask)) & (18446744073709551615UL);
    }
}
