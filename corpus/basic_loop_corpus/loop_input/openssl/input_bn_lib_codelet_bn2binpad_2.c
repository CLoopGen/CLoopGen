#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *a;
unsigned char *to;
int tolen;
int inc;
int xor;
int carry;
size_t i;
size_t lasti;
size_t j;
size_t atop;
size_t mask;
unsigned long l;

void init_vars() {
    const size_t data_size = 262144; // 256 KB for ~0.01 sec runtime estimate

    tolen = data_size;
    inc = 1;
    xor = 0x55;
    carry = 0;
    i = 0;
    lasti = 0;
    j = 0;
    atop = data_size / 2;
    mask = 0;
    l = 0;

    a = (BIGNUM *)malloc(sizeof(BIGNUM));
    a->dmax = (data_size + sizeof(unsigned long) - 1) / sizeof(unsigned long);
    a->top = a->dmax;
    a->neg = 0;
    a->flags = 0;
    a->d = (unsigned long *)calloc(a->dmax, sizeof(unsigned long));

    for (size_t idx = 0; idx < a->dmax; idx++) {
        a->d[idx] = 0xABCDEF0123456789UL ^ idx;
    }

    to = (unsigned char *)malloc(tolen * sizeof(unsigned char));
    if (!to) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}