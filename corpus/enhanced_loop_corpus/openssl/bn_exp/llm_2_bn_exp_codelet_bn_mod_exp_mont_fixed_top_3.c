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

extern int i;
extern int top;
extern BIGNUM am;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    int i;
    int limit = top - (top % 2); // Ensure even boundary for unrolling
    for (i = am.top; i < limit; i += 2) {
        am.d[i]     = 0;
        am.d[i + 1] = 0;
    }
    // Handle leftover element if any
    for (; i < top; i++) {
        am.d[i] = 0;
    }
}
