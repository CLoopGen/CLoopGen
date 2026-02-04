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
        unsigned long high = (a->d[i] >> 32) & 4294967295UL;
        unsigned long low = a->d[i] & 4294967295UL;

        if (high != 0 || low != 0) {
            ret = ((ret << 32) | high) % w;
            ret = ((ret << 32) | low) % w;
        }
    }
}
