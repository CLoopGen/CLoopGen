#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *a;
int i;
unsigned int lb;
unsigned int rb;
unsigned long *t;
unsigned long *f;
unsigned long l;
unsigned long m;
unsigned long rmask;

void init_vars() {
    lb = 32;
    rb = 32;
    rmask = 0xFFFFFFFFUL;
    l = 0x12345678UL;

    a = (BIGNUM *)malloc(sizeof(BIGNUM));
    a->dmax = 2048;
    a->top = 2048;
    a->neg = 0;
    a->flags = 0;
    a->d = (unsigned long *)calloc(a->dmax, sizeof(unsigned long));

    f = (unsigned long *)calloc(a->top, sizeof(unsigned long));
    t = (unsigned long *)calloc(a->top, sizeof(unsigned long));

    for (int j = 0; j < a->top; j++) {
        f[j] = 0xABCDEF00UL + j;
    }
}