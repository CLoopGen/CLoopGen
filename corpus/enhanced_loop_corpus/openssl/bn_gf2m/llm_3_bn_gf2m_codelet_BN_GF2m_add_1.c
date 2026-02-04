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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    int start = i;
    for (i = at->top - 1; i >= start; i--) {
        r->d[i] = at->d[i];
    }
    i = at->top; // Ensure loop condition is satisfied after reverse traversal
}
