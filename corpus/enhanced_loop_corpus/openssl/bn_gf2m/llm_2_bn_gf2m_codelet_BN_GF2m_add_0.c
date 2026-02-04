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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < bt->top; i += 2) {
        r->d[i] = at->d[i] ^ bt->d[i];
        if (i + 1 < bt->top) {
            r->d[i + 1] = at->d[i + 1] ^ bt->d[i + 1];
        }
    }
}
