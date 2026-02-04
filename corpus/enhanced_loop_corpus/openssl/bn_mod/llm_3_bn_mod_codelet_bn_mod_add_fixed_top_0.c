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
    // Variant 2: Strided Memory Access (Stride of 2 forward, then fill back)
    // Simulates non-unit stride access pattern; processes every second element first, then fills gaps
    // This creates a strided memory access pattern which may stress cache performance but tests irregular access resilience

    size_t step = 2;
    size_t pass;

    // First pass: process even indices (0, 2, 4, ...)
    for (pass = 0; pass < step; pass++) {
        for (i = pass, ai = pass, bi = pass, carry = 0; i < mtop; ) {
            mask = (unsigned long)0 - ((i - a->top) >> (8 * sizeof(i) - 1));
            temp = ((ap[ai] & mask) + carry) & 18446744073709551615UL;
            carry = (temp < carry);

            mask = (unsigned long)0 - ((i - b->top) >> (8 * sizeof(i) - 1));
            tp[i] = ((bp[bi] & mask) + temp) & 18446744073709551615UL;
            carry += (tp[i] < temp);

            i += step;
            ai += ((ai + step < (size_t)a->dmax)) ? step : 0;
            bi += ((bi + step < (size_t)b->dmax)) ? step : 0;
        }
    }
}
