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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (a->top < a->dmax) {
        for (i = a->top; i < a->dmax; i += 2) {
            a->d[i] = 0;
            if ((i + 1) < a->dmax)
                a->d[i + 1] = 0;
        }
    }
}
