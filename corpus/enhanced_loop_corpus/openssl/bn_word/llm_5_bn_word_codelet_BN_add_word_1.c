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
extern unsigned long w;
extern unsigned long l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < a->top && w != 0; i++) {
    a->d[i] = l = (a->d[i] + w);
    w = (l < w) ? 1 : 0;
}
}
