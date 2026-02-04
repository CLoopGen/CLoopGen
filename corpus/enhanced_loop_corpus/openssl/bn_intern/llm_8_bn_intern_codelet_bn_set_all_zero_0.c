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
    int start = a->top;
    int limit = a->dmax;
    for (i = start; i < limit; i += 2) {
        if (i < limit) a->d[i] = 0;
        if (i + 1 < limit) a->d[i + 1] = 0;
    }
}
