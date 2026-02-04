#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *b;
int top;
int idx;
int i;
int j;
int width;
unsigned long *table;

void init_vars() {
    top = 65536;
    width = 2;
    idx = 0;
    b = (BIGNUM *)malloc(sizeof(BIGNUM));
    b->d = (unsigned long *)malloc(top * sizeof(unsigned long));
    b->top = top;
    b->dmax = top;
    b->neg = 0;
    b->flags = 0;

    for (int k = 0; k < top; k++) {
        b->d[k] = (unsigned long)(k * 2 + 1);
    }

    table = (unsigned long *)malloc((idx + width * (top - 1) + 1) * sizeof(unsigned long));
}