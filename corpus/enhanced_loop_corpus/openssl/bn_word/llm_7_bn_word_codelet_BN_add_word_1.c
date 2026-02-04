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

extern BIGNUM *a;
extern unsigned long w;
extern unsigned long l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate use of 'l' as loop-carried dependency by inlining its value,
    // thus removing a RAW dependency on 'l' and reducing loop-carried state to only 'w'.
    // This changes data flow but preserves arithmetic outcome.
    for (i = 0; w != 0 && i < a->top; i++) {
        unsigned long old_w = w;
        a->d[i] = (a->d[i] + w) & (18446744073709551615UL);
        w = (old_w > a->d[i]) ? 1 : 0;
    }
}
