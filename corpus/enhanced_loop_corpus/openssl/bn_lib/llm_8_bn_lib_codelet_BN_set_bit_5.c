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
    int start = a->top;
    int end = i + 1;
    for (k = start; k < end; k += 2) {
        a->d[k] = 0;
        if (k + 1 < end) {
            a->d[k + 1] = 0;
        }
    }
}
