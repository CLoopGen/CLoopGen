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
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive access from high to low index
    for (k = i; k >= a->top; k--)
        a->d[k] = 0;
}
