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
    if (bt->top <= 0) return;
    for (i = 0; i < bt->top; i++) {
        if (at->d[i] == 0) continue;
        r->d[i] = at->d[i] ^ bt->d[i];
    }
}
