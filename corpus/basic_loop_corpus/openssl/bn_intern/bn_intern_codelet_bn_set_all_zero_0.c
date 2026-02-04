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
for (i = a->top; i < a->dmax; i++)
    a->d[i] = 0;

}
