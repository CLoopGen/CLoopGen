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



void loop(){
    for (k = a->top; k < i + 1; k++) {
        a->d[k] = 0;
        a->d[k] ^= 0; // Introduces a WAW dependency: write-after-write on a->d[k]
    }
}
