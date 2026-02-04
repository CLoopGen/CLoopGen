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

static unsigned long ap_data[16384];
static unsigned long rp_data[16384];
static BIGNUM a_storage;

BIGNUM *a = &a_storage;
unsigned long *ap = ap_data;
unsigned long *rp = rp_data;
unsigned long t = 0;
unsigned long c = 0;
int i = 0;

void init_vars() {
    a->d = ap_data;
    a->top = 16384;
    a->dmax = 16384;
    a->neg = 0;
    a->flags = 0;

    for (int j = 0; j < 16384; j++) {
        ap_data[j] = (unsigned long)(0xABCDEF0123456789ULL ^ (j * 31));
    }

    c = 1;
}