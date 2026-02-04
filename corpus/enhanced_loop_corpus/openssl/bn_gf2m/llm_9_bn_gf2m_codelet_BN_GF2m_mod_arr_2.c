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
    // Variant 2: Reduced effective trip count by unrolling and processing two elements per iteration
    // Maintains correctness for even a->top values; includes bounds check to handle odd sizes safely
    int limit = a->top;
    for (j = 0; j < limit; j += 2) {
        r->d[j] = a->d[j];
        if (j + 1 < limit) {
            r->d[j + 1] = a->d[j + 1];
        }
    }
}
