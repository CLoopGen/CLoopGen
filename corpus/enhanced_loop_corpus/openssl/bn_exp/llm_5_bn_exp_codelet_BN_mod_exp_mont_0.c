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

extern  BIGNUM *m;
extern int i;
extern int j;
extern BIGNUM *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < j; i++) {
        r->d[i] = (i > m->top || i < r->top) ? 
                  0 : 
                  (~m->d[i]) & (18446744073709551615UL);
    }
}
