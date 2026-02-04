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
    unsigned long temp = 0;
    for (k = a->top; k < i + 1; k++) {
        a->d[k] = temp; // Removes direct data dependency on previous writes to a->d[k]
        temp = 0;       // Eliminates loop-carried dependency by using local temporary
    }
}
