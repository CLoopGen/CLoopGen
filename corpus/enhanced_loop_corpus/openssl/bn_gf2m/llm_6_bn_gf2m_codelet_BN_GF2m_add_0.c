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
    uint64_t temp;
    for (i = 0; i < bt->top; i++) {
        temp = at->d[i] ^ bt->d[i];
        r->d[i] = temp;
    }
}
