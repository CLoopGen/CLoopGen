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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int i;
    for (i = a->top; i < a->dmax; i += 2)
        a->d[i] = 0;
    // Handle odd indices if dmax is odd and top allows
    for (i = a->top + 1; i < a->dmax; i += 2)
        a->d[i] = 0;
}
