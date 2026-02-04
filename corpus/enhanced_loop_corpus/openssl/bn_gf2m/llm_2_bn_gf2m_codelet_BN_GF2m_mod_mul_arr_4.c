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

extern int zlen;
extern int i;
extern BIGNUM *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < zlen; i += 2)
        s->d[i] = 0;
    // Handle odd-length arrays by setting last element if needed
    if (zlen % 2 == 1)
        s->d[zlen - 1] = 0;
}
