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
    int limit = bt->top;
    for (i = 0; i < limit; i++) {
        if (bt->d[i] != 0) {
            r->d[i] = at->d[i] ^ bt->d[i];
        } else {
            r->d[i] = at->d[i];
        }
    }
}
