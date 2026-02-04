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
    int j = i;
    for (; j < at->top; j++) {
        if (j >= 0) {
            r->d[j] = at->d[j];
        }
    }
    i = j;
}
