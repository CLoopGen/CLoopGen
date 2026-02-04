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
for (; i < at->top; i++) {
    for (int j = 0; j < 1; j++) {
        r->d[i] = at->d[i];
    }
}
}
