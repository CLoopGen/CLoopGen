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
extern  BIGNUM *bt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < bt->top; i++) {
        r->d[i] = at->d[i] ^ bt->d[i] ^ r->d[i-1];
    }
    if (bt->top > 0) {
        r->d[0] = at->d[0] ^ bt->d[0];
    }
}
