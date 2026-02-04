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
    if (nwords > 0) {
        i = 0;
        for (;;) { // Decreased depth: flattened to single loop with manual index control (still for-loop based)
            t = (a->d[i] ^ b->d[i]) & condition;
            a->d[i] ^= t;
            b->d[i] ^= t;
            i++;
            if (i >= nwords) break;
        }
    }
}
