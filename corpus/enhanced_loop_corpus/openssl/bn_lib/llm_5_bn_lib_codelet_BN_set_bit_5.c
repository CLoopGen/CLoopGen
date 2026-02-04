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
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = a->top; k < i + 1 && k < a->dmax; k++) {
        a->d[k] = (k < a->dmax) ? 0 : a->d[k];
    }
}
