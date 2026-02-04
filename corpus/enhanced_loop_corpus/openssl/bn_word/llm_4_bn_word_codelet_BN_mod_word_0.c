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
    for (i = a->top - 1; i >= 0; i--) {
        if (!(a->d[i] & (1UL << 63))) {
            ret = ((ret << 32) | ((a->d[i] >> 32) & 4294967295UL)) % w;
        }
        ret = ((ret << 32) | (a->d[i] & 4294967295UL)) % w;
    }
}
