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
    // Variant 1: Strided memory access (stride of 2) with bounds adjustment
    int start = a->top - 1;
    for (i = (start % 2 == 0) ? start - (start & 1) : start; i > 0; i -= 2) {
        m = l << lb;
        l = f[i - 1];
        t[i] = (m | ((l >> rb) & rmask)) & (18446744073709551615UL);
    }
    // Handle remaining element if needed (for correctness in strided pattern)
    if ((a->top - 1) > 0 && (a->top - 1) % 2 == 0) {
        i = 1;
        m = l << lb;
        l = f[i - 1];
        t[i] = (m | ((l >> rb) & rmask)) & (18446744073709551615UL);
    }
}
