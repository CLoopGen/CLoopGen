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
extern unsigned long w;
extern unsigned long ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    for (i = (a->top > 64 ? 64 : a->top) - 1; i >= 0; i--) {
        unsigned long high = (a->d[i] >> 32) & 0xFFFFFFFFUL;
        unsigned long low = a->d[i] & 0xFFFFFFFFUL;
        ret = (ret * 0x100000000UL + high) % w;
        ret = (ret * 0x100000000UL + low) % w;
    }
}
