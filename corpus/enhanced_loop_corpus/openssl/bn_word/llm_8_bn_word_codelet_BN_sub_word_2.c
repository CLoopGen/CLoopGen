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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < a->top && w > 0; ) {
        if (a->d[i] >= w) {
            a->d[i] -= w;
            break;
        } else {
            unsigned long borrow = w - a->d[i];
            a->d[i] = 18446744073709551615UL - borrow + 1;
            i++;
            w = 1;
        }
    }
}
