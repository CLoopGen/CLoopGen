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
    uint64_t temp;
    for (; i < at->top; i++) {
        temp = at->d[i];
        r->d[i] = temp;
    }
}
