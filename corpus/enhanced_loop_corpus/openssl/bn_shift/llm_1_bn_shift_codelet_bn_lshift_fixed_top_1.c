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
for (i = a->top - 1; i > 0; i--) {
    if (i > 0) {
        m = l << lb;
        l = f[i - 1];
        t[i] = (m | ((l >> rb) & rmask)) & (18446744073709551615UL);
    }
}
}
