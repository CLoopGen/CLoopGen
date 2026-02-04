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

extern unsigned long condition;
extern BIGNUM *a;
extern BIGNUM *b;
extern int nwords;
extern unsigned long t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Iterates from the last element to the first
    for (i = nwords - 1; i >= 0; i--) {
        t = (a->d[i] ^ b->d[i]) & condition;
        a->d[i] ^= t;
        b->d[i] ^= t;
    }
}
