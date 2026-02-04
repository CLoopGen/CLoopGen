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

static unsigned long *r_d;
static unsigned long *at_d;
BIGNUM *r;
BIGNUM *at;
int i;

void init_vars() {
    const int data_size = 131072; // ~128KB assuming unsigned long is 8 bytes

    r_d = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    at_d = (unsigned long *)calloc(data_size, sizeof(unsigned long));

    r = (BIGNUM *)malloc(sizeof(BIGNUM));
    at = (BIGNUM *)malloc(sizeof(BIGNUM));

    r->d = r_d;
    r->top = 0;
    r->dmax = data_size;
    r->neg = 0;
    r->flags = 0;

    at->d = at_d;
    at->top = data_size;
    at->dmax = data_size;
    at->neg = 0;
    at->flags = 0;

    i = 0;

    for (int j = 0; j < data_size; j++) {
        at_d[j] = (unsigned long)(j ^ 0xdeadbeef);
    }
}