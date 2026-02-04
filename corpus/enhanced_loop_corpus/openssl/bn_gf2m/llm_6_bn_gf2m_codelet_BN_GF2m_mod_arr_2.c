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
    // Variant 1: Introduce a WAW (Write-After-Write) dependency by splitting the write into two steps
    // and introducing a temporary variable with a loop-carried dependence to enforce ordering.
    uint64_t temp;
    for (j = 0; j < a->top; j++) {
        temp = a->d[j];         // Intermediate use of data
        r->d[j] = temp;         // Redundant assignment chain introduces WAW-like pattern across iterations
    }
}
