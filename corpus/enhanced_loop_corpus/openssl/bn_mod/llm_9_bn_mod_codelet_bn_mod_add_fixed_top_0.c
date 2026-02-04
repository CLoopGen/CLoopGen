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
extern unsigned long carry;
extern unsigned long temp;
extern unsigned long mask;
extern unsigned long *tp;
extern  unsigned long *ap;
extern  unsigned long *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t unroll_factor = 2;
size_t end = mtop - (mtop % unroll_factor);
for (i = 0, ai = 0, bi = 0, carry = 0; i < end; i += unroll_factor) {
    for (size_t u = 0; u < unroll_factor; u++) {
        size_t idx = i + u;
        mask = (unsigned long)0 - ((idx - a->top) >> (8 * sizeof(idx) - 1));
        temp = ((ap[ai] & mask) + carry) & (18446744073709551615UL);
        carry = (temp < carry);
        mask = (unsigned long)0 - ((idx - b->top) >> (8 * sizeof(idx) - 1));
        tp[idx] = ((bp[bi] & mask) + temp) & (18446744073709551615UL);
        carry += (tp[idx] < temp);
        ai += (idx + 1 >= a->dmax) ? 1 : 0;
        bi += (idx + 1 >= b->dmax) ? 1 : 0;
    }
}
for (; i < mtop; i++) {
    mask = (unsigned long)0 - ((i - a->top) >> (8 * sizeof(i) - 1));
    temp = ((ap[ai] & mask) + carry) & (18446744073709551615UL);
    carry = (temp < carry);
    mask = (unsigned long)0 - ((i - b->top) >> (8 * sizeof(i) - 1));
    tp[i] = ((bp[bi] & mask) + temp) & (18446744073709551615UL);
    carry += (tp[i] < temp);
    ai += (i + 1 >= a->dmax) ? 1 : 0;
    bi += (i + 1 >= b->dmax) ? 1 : 0;
}
}
