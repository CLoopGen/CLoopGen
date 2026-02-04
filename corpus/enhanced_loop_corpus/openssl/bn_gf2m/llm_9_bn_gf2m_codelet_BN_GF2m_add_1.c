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
    int stride = 2;
    for (; i < at->top; i += stride) {
        r->d[i] = at->d[i];
        if (i + 1 < at->top) {
            r->d[i + 1] = at->d[i + 1];
        }
    }
}
