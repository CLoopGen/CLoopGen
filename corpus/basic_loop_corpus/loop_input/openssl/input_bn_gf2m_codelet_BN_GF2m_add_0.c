#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *r;
int i;
BIGNUM *at;
BIGNUM *bt;

void init_vars() {
    const int data_size = 131072 / sizeof(unsigned long); // ~128KB of data

    at = (BIGNUM *)malloc(sizeof(BIGNUM));
    bt = (BIGNUM *)malloc(sizeof(BIGNUM));
    r = (BIGNUM *)malloc(sizeof(BIGNUM));

    at->d = (unsigned long *)malloc(data_size * sizeof(unsigned long));
    bt->d = (unsigned long *)malloc(data_size * sizeof(unsigned long));
    r->d = (unsigned long *)malloc(data_size * sizeof(unsigned long));

    at->top = data_size;
    bt->top = data_size;
    r->top = data_size;

    at->dmax = data_size;
    bt->dmax = data_size;
    r->dmax = data_size;

    at->neg = 0;
    bt->neg = 0;
    r->neg = 0;

    at->flags = 0;
    bt->flags = 0;
    r->flags = 0;

    for (int j = 0; j < data_size; j++) {
        at->d[j] = (unsigned long)(j * 31);
        bt->d[j] = (unsigned long)(j * 17);
        r->d[j] = 0;
    }
}