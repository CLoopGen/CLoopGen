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
    unsigned long temp_ret = ret;
    for (i = a->top - 1; i >= 0; i--) {
        unsigned long hi = (a->d[i] >> 32) & 4294967295UL;
        unsigned long lo = a->d[i] & 4294967295UL;
        temp_ret = ((temp_ret << 32) | hi) % w;
        temp_ret = ((temp_ret << 32) | lo) % w;
    }
    ret = temp_ret;
}
