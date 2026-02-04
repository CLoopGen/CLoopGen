#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

int zlen;
int i;
BIGNUM *s;

void init_vars() {
    zlen = 131072 / sizeof(unsigned long);
    s = (BIGNUM *)malloc(sizeof(BIGNUM));
    s->d = (unsigned long *)calloc(zlen, sizeof(unsigned long));
    s->top = 0;
    s->dmax = zlen;
    s->neg = 0;
    s->flags = 0;
}