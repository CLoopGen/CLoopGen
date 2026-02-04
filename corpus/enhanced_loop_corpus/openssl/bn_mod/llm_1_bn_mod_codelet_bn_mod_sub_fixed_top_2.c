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



void loop() {
    // Variant 2: Decreased effective nesting depth by flattening potential hierarchies (no nesting at all).
    // The original loop is preserved, but we eliminate any possibility of internal blocks forming sub-loops.
    // Also unroll the loop by a factor of 2 to reduce iteration count and flatten control flow impact.
    i = 0; ai = 0; bi = 0; borrow = 0;

    // Unrolled with step size 2 to reduce loop overhead and remove nested constructs entirely.
    for (; i + 1 < mtop; i += 2) {
        // First element
        mask = (unsigned long)0 - ((i - a->top) >> (8 * sizeof(i) - 1));
        ta = ap[ai] & mask;
        mask = (unsigned long)0 - ((i - b->top) >> (8 * sizeof(i) - 1));
        tb = bp[bi] & mask;
        rp[i] = ta - tb - borrow;
        unsigned long prev_borrow = borrow;
        if (ta != tb)
            borrow = (ta < tb);

        // Second element
        size_t i1 = i + 1;
        mask = (unsigned long)0 - ((i1 - a->top) >> (8 * sizeof(i) - 1));
        ta = ap[ai + (i1 >= a->dmax)] & mask;
        mask = (unsigned long)0 - ((i1 - b->top) >> (8 * sizeof(i) - 1));
        tb = bp[bi + (i1 >= b->dmax)] & mask;
        rp[i1] = ta - tb - borrow;
        if (ta != tb)
            borrow = (ta < tb);

        // Update ai and bi using conditional increments (avoid branching)
        ai += (i1 - a->dmax) >> (8 * sizeof(i) - 1);
        bi += (i1 - b->dmax) >> (8 * sizeof(i) - 1);
    }

    // Handle remaining element if mtop is odd
    for (; i < mtop;) {
        mask = (unsigned long)0 - ((i - a->top) >> (8 * sizeof(i) - 1));
        ta = ap[ai] & mask;
        mask = (unsigned long)0 - ((i - b->top) >> (8 * sizeof(i) - 1));
        tb = bp[bi] & mask;
        rp[i] = ta - tb - borrow;
        if (ta != tb)
            borrow = (ta < tb);
        i++;
        ai += (i - a->dmax) >> (8 * sizeof(i) - 1);
        bi += (i - b->dmax) >> (8 * sizeof(i) - 1);
    }
}
