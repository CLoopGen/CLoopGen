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

extern BIGNUM *r;
extern int i;
extern  BIGNUM *at;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < at->top - 1; i++) {
        r->d[i + 1] = at->d[i];
    }
    if (at->top > 0 && i == at->top - 1) {
        r->d[i] = at->d[i];
    }
}
