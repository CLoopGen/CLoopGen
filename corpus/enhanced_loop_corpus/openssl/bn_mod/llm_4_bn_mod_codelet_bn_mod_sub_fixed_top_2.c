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

extern  BIGNUM *a;
extern  BIGNUM *b;
extern size_t i;
extern size_t ai;
extern size_t bi;
extern size_t mtop;
extern unsigned long borrow;
extern unsigned long ta;
extern unsigned long tb;
extern unsigned long mask;
extern unsigned long *rp;
extern  unsigned long *ap;
extern  unsigned long *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , ai = 0 , bi = 0 , borrow = 0; i < mtop;) {
    mask = (unsigned long)0 - ((i - a->top) >> (8 * sizeof (i) - 1));
    ta = ap[ai] & mask;
    mask = (unsigned long)0 - ((i - b->top) >> (8 * sizeof (i) - 1));
    tb = bp[bi] & mask;
    rp[i] = ta - tb - borrow;
    borrow = (ta < tb) ? 1 : (ta == tb) ? borrow : 0;
    i++;
    ai += (i > a->dmax - 1) ? 0 : 1;
    bi += (i > b->dmax - 1) ? 0 : 1;
}
}
