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
extern  BIGNUM *a;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < a->top && a != NULL && r != NULL; j++) {
        r->d[j] = a->d[j];
    }
}
