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

extern BIGNUM *a;
extern unsigned long w;
extern unsigned long l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from top to bottom)
    for (i = a->top - 1; w != 0 && i >= 0; i--) {
        a->d[i] = l = (a->d[i] + w) & (18446744073709551615UL);
        w = (w > l) ? 1 : 0;
    }
}
