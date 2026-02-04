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
extern  BIGNUM *a;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse the array from top-1 down to 0
    int j;
    for (j = a->top - 1; j >= 0; j--) {
        r->d[j] = a->d[j];
    }
}
